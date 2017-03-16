#include "CartesianPoint.h"
#include "PolarPoint.h"
#include "Angle.h"

CartesianPoint::CartesianPoint(float _x, float _y, float _z){
	mx = _x;
	my = _y;
	mz = _z;
}

const CartesianPoint CartesianPoint::multi(const float n) const {
	return CartesianPoint(
		mx * n,
		my * n,
		mz * n
	);
}

const CartesianPoint CartesianPoint::operator+(const CartesianPoint c) const {
	return CartesianPoint(
		mx + c.mx,
		my + c.my,
		mz + c.mz
	);
}

const CartesianPoint CartesianPoint::operator-(const CartesianPoint c) const {
	return CartesianPoint(
		mx - c.mx,
		my - c.my,
		mz - c.mz
	);
}

const PolarPoint CartesianPoint::toPolar(){
	float y_dash = hypot(mx, my) - ARM_R0_LENGTH;
	float r = hypot(mz, y_dash);
	Angle theta;
	// y‚ª\•ª‚É¬‚³‚¯‚ê‚ÎAù‰ñŠp‚Í0
	if(my <= 0.001){
		theta = Angle::deg(0);
	}else{
		theta = Angle::rad(atan2(mx, my));
	}
	Angle phi = Angle::rad(atan2(mz, y_dash));
	return PolarPoint(r, theta, phi);
}

void CartesianPoint::print(){
	Serial.print("(x, y, z) = (");
	Serial.print(mx);
	Serial.print(",");
	Serial.print(my);
	Serial.print(",");
	Serial.print(mz);
	Serial.println(").");
}