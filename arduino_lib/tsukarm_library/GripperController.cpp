#include "GripperController.h"
#include "BezierStepper.h"
#include "Arduino.h"

GripperController::GripperController(float tp, bool abs){
	stepper = new BezierStepper(Square(0.6f, 0.0f), Square(0.4f, 1.0f), Square(1.0f, 1.0f));
	is_absolute = abs;
    Angle closing_angle = Angle::deg(100);
    if(is_absolute){
        target_angle = closing_angle.multi(1.0f - tp);
    }else{
        target_angle = closing_angle.multi(-1.0f * tp);
    }
}

GripperController::~GripperController(){
	delete stepper;
    stepper = NULL;
}

void GripperController::initialize(Angle a){
	start_angle = a;
}

Angle GripperController::call(float t){
    Angle delta, result;
    if(is_absolute){
        delta = target_angle - start_angle;
        result = start_angle + delta.multi(stepper->call(t));
    }else{
        delta = target_angle;
        result = start_angle + delta.multi(stepper->call(t));
    }
    if(result.toDeg() <= 0){
        return Angle::deg(0);
    }else if(result.toDeg() >= 100){
        return Angle::deg(100);
    }
    return result;
}

