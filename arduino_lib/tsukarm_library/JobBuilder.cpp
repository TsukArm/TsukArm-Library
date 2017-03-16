#include "JobBuilder.h"
#include "BezierStepper.h"
#include "BezierFunction.h"
#include "LinearFunction.h"
#include "LinearRotator.h"
#include "ReferenceRotator.h"
#include "GripperController.h"
#include "CartesianJob.h"
#include "Arduino.h"

JobBuilder::JobBuilder(RobotArm *a){
	arm = a;
	rm = RotateMatrix();
	reset();
}

void JobBuilder::reset(){
	kind = MOVE_LINEAR;
	p2x = 0.0;
	p2y = 0.0;
	p2z = 0.0;
	p3x = 0.0;
	p3y = 0.0;
	p3z = 0.0;
	target_x = 0.0;
	target_y = 0.0;
	target_z = 0.0;
	target_r = 0.0;
	target_p = 0.0;
	target_yaw = 0.0;
	prev_rm = rm;
	rm = RotateMatrix();
	gripper = 0.0;
	function_is_absolute = false;
	rotator_is_absolute = false;
	gripper_is_absolute = false;
	moving_time = 100;
	interval = 1000;
}

bool JobBuilder::setMoving(int k){
	kind = k;
	return true;
}

bool JobBuilder::setTargetPosition(float x, float y, float z){
	target_x = x;
	target_y = y;
	target_z = z;
	function_is_absolute = true;
	return true;
}

bool JobBuilder::setMiddlePosition(int k, float x, float y, float z){
    // 中間点を使うので、MOVE_BEZIER一択
    kind = MOVE_BEZIER;
	if(k == MID_FIRST){
		p2x = x;
		p2y = y;
		p2z = z;
	}else{
		p3x = x;
		p3y = y;
		p3z = z;
	}
	return true;
}

bool JobBuilder::setTargetRoll(float deg){
	target_r = deg+90.0;
	rotator_is_absolute = true;
	return true;
}

bool JobBuilder::setTargetPitch(float deg){
	target_p = deg+90.0;
	rotator_is_absolute = true;
	return true;
}

bool JobBuilder::setTargetYaw(float deg){
	target_yaw = deg+90.0;
	rotator_is_absolute = true;
	return true;
}

bool JobBuilder::setRollSystem(bool is_local){
	if(is_local){
		rm.set(0, 0.0);
		rm.set(3, 0.0);
	}else{
		rm.set(0, 1.0);
		rm.set(3, -90.0);
	}
	return true;
}

bool JobBuilder::setPitchSystem(bool is_local){
	if(is_local){
		rm.set(6, 0.0);
		rm.set(7, 0.0);
	}else{
		rm.set(6, -1.0);
		rm.set(7, 60.0);
	}
	return true;
}

bool JobBuilder::setGripper(float rate){
	gripper_is_absolute = true;
	gripper = rate;
	return true;
}

bool JobBuilder::setMovingTime(int ms){
	moving_time = ms / 10;
	return true;
}

bool JobBuilder::setInterval(int ms){
	interval = ms;
	return true;
}

Job* JobBuilder::build(){
	Job *result;
	// ジョブを作成する
	// Functionを作成する
	Function **f = new Function*[1];
	if(kind == MOVE_BEZIER){
		f[0] = new BezierFunction(
			CartesianPoint(p2x, p2y, p2z),
			CartesianPoint(p3x, p3y, p3z),
			CartesianPoint(target_x, target_y, target_z),
			true,
		    buildStepper()
		);
	}else{
		f[0] = new LinearFunction(
			CartesianPoint(target_x, target_y, target_z),
			function_is_absolute,
		    buildStepper()
		);
	}
	// Rotatorを作成する
	Rotator **r = new Rotator*[2];
	r[0] = new LinearRotator(
		HeadRotation(Angle::deg(target_r), Angle::deg(target_p), Angle::deg(target_yaw)),
		rotator_is_absolute,
		prev_rm,
		arm,
	    buildStepper()
	);
	r[1] = new ReferenceRotator(arm, rm, buildStepper());
	// GripperControllerを作成する
	GripperController *g = new GripperController(gripper, gripper_is_absolute);
	result = new CartesianJob(arm, f, 1, r, 2, g, moving_time, interval);
	// 次のbuildに向けて初期化する
	reset();
	return result;
}

Stepper* JobBuilder::buildStepper(){
    return new BezierStepper(Square(0.3, 0.0), Square(0.7, 1.0), Square(1.0, 1.0));
}
