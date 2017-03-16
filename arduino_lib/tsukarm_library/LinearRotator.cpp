#include "LinearRotator.h"

LinearRotator::LinearRotator(HeadRotation t, bool abs, Stepper *s) : Rotator(s) {
	target_rotation = t;
	is_absolute = abs;
	arm = NULL;
}

LinearRotator::LinearRotator(HeadRotation t, bool abs, RotateMatrix im, RobotArm *a, Stepper *s) : Rotator(s) {
	target_rotation = t;
	is_absolute = abs;
	init_matrix = im;
	arm = a;
}

void LinearRotator::initialize(HeadRotation rot){
	if(arm != NULL){
		HeadRotation tmp = init_matrix.vector_multi(arm->angle(0), arm->angle(1), arm->angle(2));
    	rotation = rot - tmp;
	}else{
		rotation = rot;
	}
}

HeadRotation LinearRotator::call(float x){
	HeadRotation target = target_rotation;
	if(is_absolute){
		target = target_rotation - rotation;
	}
	return rotation + target.multi(x);
}
