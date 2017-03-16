#include "Rotator.h"
#include "Arduino.h"

Rotator::Rotator(){
	stepper = new Stepper();
}

Rotator::Rotator(Stepper *s){
	stepper = s;
}

Rotator::~Rotator(){
	delete stepper;
    stepper = NULL;
}

void Rotator::initialize(HeadRotation rot){
	rotation = rot;
}

HeadRotation Rotator::_call(float t){
	return call(stepper->call(t));
}

HeadRotation Rotator::call(float x){
	return rotation;
}
