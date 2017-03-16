#include "PolarPoint.h"
#include "ServoPoint.h"

PolarPoint::PolarPoint(float _r, Angle t, Angle p){
	r = _r;
	theta = t;
	phi = p;
}

const CartesianPoint PolarPoint::toCartesian(){
	float r_dash = r * cos(phi.toRad()) + ARM_R0_LENGTH;
	return CartesianPoint(
		r_dash * sin(theta.toRad()),
		r_dash * cos(theta.toRad()),
		r * sin(phi.toRad())
	);
}

const ServoPoint PolarPoint::toServo(){
	Angle alpha = cosineFomula(ARM_R1_LENGTH, ARM_R2_LENGTH, r);
	Angle beta = cosineFomula(ARM_R2_LENGTH, ARM_R1_LENGTH, r);
	Angle angles[] = {theta + Angle::deg(90), phi + beta, alpha - phi + Angle::deg(65)};
	return ServoPoint(angles);
}

// ó]å∑íËóùÇ…ÇÊÇËÅAÇRï”a,b,cÇ©ÇÁäpa(rad)ÇãÅÇﬂÇÈ
Angle PolarPoint::cosineFomula(float a, float b, float c){
	float tmp = (b * b + c * c - a * a) / (2.0 * b * c);
	return Angle::rad(acos(tmp));
}

void PolarPoint::print(){
	Serial.print("(r, theta, phi) = (");
	Serial.print(r);
	Serial.print(",");
	Serial.print(theta.toDeg());
	Serial.print(",");
	Serial.print(phi.toDeg());
	Serial.println(").");
}

