#include "ServoPoint.h"
#include "Constant.h"

ServoPoint::ServoPoint(Angle a[]){
	for(int i=0; i<3; i++){
		angles[i] = a[i];
	}
}

Angle ServoPoint::get(int index){
	return angles[index];
}

const PolarPoint ServoPoint::toPolar(){
	Angle inc_angle = Angle::deg(245) - angles[1] - angles[2];
	Angle alpha = Angle::rad(POLAR_ALPHA_ANGLES[inc_angle.toDeg()]);
	float tmp = sin(alpha.toRad());
	float r = ARM_R1_LENGTH * sin(inc_angle.toRad()) / tmp;
	Angle theta = angles[0] - Angle::deg(90);
	Angle phi = alpha - angles[2] + Angle::deg(65);
	return PolarPoint(r, theta, phi);
}

void ServoPoint::print(){
	Serial.print("(m0, m1, m2) = (");
	Serial.print(angles[0].toDeg());
	Serial.print(",");
	Serial.print(angles[1].toDeg());
	Serial.print(",");
	Serial.print(angles[2].toDeg());
	Serial.println(").");
}

