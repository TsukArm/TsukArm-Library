#include "RobotArm.h"
#include "arduino.h"

RobotArm::RobotArm(){
	int pins[] = {2, 3, 4, 5, 6, 7, 8};
	for(int i=0; i<SERVO_COUNT; i++){
		servos[i].attach(pins[i], MIN_PULSE, MAX_PULSE);
	}
}

void RobotArm::offset(int o[]){
	for(int i=0; i<SERVO_COUNT; i++){
		offsets[i] = Angle::deg(o[i]);
	}
}

void RobotArm::initialMove(){
	for(int i=0; i<SERVO_COUNT; i++){
		servoWrite(i, Angle::deg(INITIAL_ANGLES[i]));
	}
}

void RobotArm::servoWrite(int servo_num, Angle angle){
	Angle b = angle + offsets[servo_num];
	servos[servo_num].writeMicroseconds(b.toUs());
	current_angles[servo_num] = angle;
}

void RobotArm::servoUsWrite(int servo_num, int us_angle){
	Angle a = Angle::us(us_angle);
	servoWrite(servo_num, a);
}

Angle RobotArm::angle(int i){
	return current_angles[i];
}

// us指定のまま静止すると、制度の悪いサーボだと振動してしまう場合があるので、
// 強制的に近似するDEGに再指定してしまうためのメソッド
// servo#read()を利用するため、無理な角度で静止してしまうと制動が狂う点に注意
void RobotArm::adjustDegree(int servo_num){
	int a = servos[servo_num].read();
	servos[servo_num].write(a);
}

