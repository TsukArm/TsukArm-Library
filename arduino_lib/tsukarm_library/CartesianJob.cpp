#include "CartesianJob.h"
#include "Angle.h"
#include "CartesianPoint.h"
#include "PolarPoint.h"
#include "ServoPoint.h"
#include "math.h"
#include "Arduino.h"

CartesianJob::CartesianJob(RobotArm *a, Function **f, int fn, Rotator **r, int rn, GripperController *g, int frame_count, int wait) : Job(frame_count, wait)
{
	arm = a;
	functions = f;
	function_num = fn;
	rotators = r;
	rotator_num = rn;
	gripper = g;
}

CartesianJob::~CartesianJob(){
	for(int i=0; i<function_num; i++){
		delete functions[i];
	    functions[i] = NULL;
	}
	delete[] functions;
    functions = NULL;
	for(int i=0; i<rotator_num; i++){
		delete rotators[i];
	    rotators[i] = NULL;
	}
	delete[] rotators;
    rotators = NULL;
	delete gripper;
    gripper = NULL;
}

void CartesianJob::initialize(){
	Angle angles[3];
	for(int i=0; i<3; i++){
		angles[i] = arm->angle(i);
	}
	ServoPoint sp = ServoPoint(angles);
	PolarPoint pp = sp.toPolar();
	CartesianPoint cp = pp.toCartesian();
	Serial.print("initial position:");
	cp.print();
	// 第１Function、第１Rotatorには現在の座標／角度を投入する
	functions[0]->initialize(cp);
	rotators[0]->initialize(HeadRotation(arm->angle(5), arm->angle(4), arm->angle(3)));
	gripper->initialize(arm->angle(6));
	// 第２以降の関数群には原点を投入する
	for(int i=1; i<function_num; i++){
		functions[i]->initialize(CartesianPoint(0.0f, 0.0f, 0.0f));
	}
	for(int i=1; i<rotator_num; i++){
		rotators[i]->initialize(HeadRotation(Angle::rad(0.0f), Angle::rad(0.0f), Angle::rad(0.0f)));
	}
}

void CartesianJob::interpolate(){
	float t = (float)frame / finish_frame;
	CartesianPoint cp = functions[0]->_call(t);
	for(int i=1; i<function_num; i++){
		cp = cp + functions[i]->_call(t);
	}
    //cp.print();
	PolarPoint pp = cp.toPolar();
	ServoPoint sp = pp.toServo();
	int func_nums[] = {0, 1, 2};
	for(int i=0; i<3; i++){
		arm->servoWrite(func_nums[i], sp.get(i));
	}
	HeadRotation hr = rotators[0]->_call(t);
	for(int i=1; i<rotator_num; i++){
		hr = hr + rotators[i]->_call(t);
	}
	int rot_nums[] = {3, 4, 5};
	for(int i=0; i<3; i++){
		arm->servoWrite(rot_nums[i], hr.get(i));
	}
	arm->servoWrite(6, gripper->call(t));
}

void CartesianJob::finalize(){
}
