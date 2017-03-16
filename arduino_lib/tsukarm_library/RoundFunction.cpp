#include "RoundFunction.h"
#include "math.h"

RoundFunction::RoundFunction(CartesianPoint c, bool abs, int cy, Stepper *s) : Function(s) {
	center = c;
	cycle = cy;
	is_absolute = abs;
}

CartesianPoint RoundFunction::call(float x){
	CartesianPoint target_center = center;
	if(!is_absolute){
		target_center = target_center + point;
	}
	CartesianPoint r = point - target_center;
	float r_dash = sqrt(pow(r.y(), 2) + pow(r.x(), 2));
	float theta = atan2(r.y(), r.x());
	float tz = x * 2 * M_PI * cycle; 
	float t =  tz + theta;
	CartesianPoint r1 = CartesianPoint(
		r_dash * cos(t),
		r_dash * sin(t),
		r.z() * cos(tz)
	);
	CartesianPoint res = target_center + r1;
	return res;
}
