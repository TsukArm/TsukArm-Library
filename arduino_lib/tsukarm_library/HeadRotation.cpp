#include "HeadRotation.h"

HeadRotation::HeadRotation(){
	_roll = Angle::rad(0);
	_pitch = Angle::rad(0);
	_yaw = Angle::rad(0);
}

HeadRotation::HeadRotation(Angle r, Angle p, Angle y){
	_roll = r;
	_pitch = p;
	_yaw = y;
}

const HeadRotation HeadRotation::operator+(const HeadRotation r) const {
	return HeadRotation(
		_roll + r.roll(),
		_pitch + r.pitch(),
		_yaw + r.yaw()
	);
}

const HeadRotation HeadRotation::operator-(const HeadRotation r) const {
	return HeadRotation(
		_roll - r.roll(),
		_pitch - r.pitch(),
		_yaw - r.yaw()
	);
}

const HeadRotation HeadRotation::multi(const float x) const {
	return HeadRotation(
		_roll.multi(x),
		_pitch.multi(x),
		_yaw.multi(x)
	);
}

Angle HeadRotation::get(int index){
	Angle angles[3];
	angles[0] = _yaw;
	angles[1] = _pitch;
	angles[2] = _roll;
	return angles[index];
}

void HeadRotation::print(){
	Serial.print("(r, p, y) = (");
	Serial.print(_roll.toDeg());
	Serial.print(",");
	Serial.print(_pitch.toDeg());
	Serial.print(",");
	Serial.print(_yaw.toDeg());
	Serial.println(").");
}
