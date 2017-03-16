#include "LinearFunction.h"
#include "Arduino.h"

LinearFunction::LinearFunction(CartesianPoint point, bool abs, Stepper *s) : Function(s) {
	target_point = point;
	is_absolute = abs;
}

CartesianPoint LinearFunction::call(float t){
	CartesianPoint delta = target_point;
	if(is_absolute){
		delta = target_point - point;
	}
	return point + delta.multi(t);
}
