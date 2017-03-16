#include "GripperController.h"
#include "BezierStepper.h"
#include "Arduino.h"

GripperController::GripperController(float tp, bool abs){
	stepper = new BezierStepper(Square(0.6f, 0.0f), Square(0.4f, 1.0f), Square(1.0f, 1.0f));
	Angle closing_angle = Angle::deg(100);
	target_angle = closing_angle.multi(1.0f - tp);
	is_absolute = abs;
}

GripperController::~GripperController(){
	delete stepper;
    stepper = NULL;
}

void GripperController::initialize(Angle a){
	start_angle = a;
}

Angle GripperController::call(float t){
	Angle delta = target_angle;
	if(is_absolute){
		delta = target_angle - start_angle;
	}
	return start_angle + delta.multi(stepper->call(t));
}

