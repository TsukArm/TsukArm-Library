#include "Function.h"
#include "Arduino.h"

Function::Function(){
	stepper = new Stepper();
}

Function::Function(Stepper *s){
	stepper = s;
}

Function::~Function(){
	delete stepper;
    stepper = NULL;
}

void Function::initialize(CartesianPoint p){
	point = p;
}

CartesianPoint Function::_call(float t){
	return call(stepper->call(t));
}

CartesianPoint Function::call(float x){
	return point;
}
