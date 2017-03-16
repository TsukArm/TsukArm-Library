#include "Angle.h"
#include "arduino.h"

Angle::Angle(){
	m_rad = 0.0f;
}

Angle::Angle(float _rad){
	m_rad = _rad;
}

int Angle::toUs(){
	float rate = m_rad / M_PI;
	return (int)rint(rate * (MAX_PULSE - MIN_PULSE)) + MIN_PULSE;
}

int Angle::toDeg(){
	return (int)rint(m_rad * 180.0f / M_PI);
}

float Angle::toRad(){
	return m_rad;
}

const Angle Angle::multi(const float x) const {
	return Angle(m_rad * x);
}

const Angle Angle::operator+(const Angle a) const {
	return Angle(m_rad + a.m_rad);
}

const Angle Angle::operator-(const Angle a) const {
	return Angle(m_rad - a.m_rad);
}

