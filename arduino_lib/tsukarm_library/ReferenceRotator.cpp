#include "ReferenceRotator.h"

ReferenceRotator::ReferenceRotator(RobotArm *a, RotateMatrix m, Stepper *s) : Rotator(s) {
	arm = a;
	matrix = m;
	init_matrix =  RotateMatrix(
		0.0, 0.0, 0.0,  0.0,
		0.0, 0.0, 0.0,  0.0,
		0.0, 0.0, 0.0,  0.0
	);
}

ReferenceRotator::ReferenceRotator(RobotArm *a, RotateMatrix m, RotateMatrix im, Stepper *s) : Rotator(s) {
	arm = a;
	matrix = m;
	init_matrix = im;
}

void ReferenceRotator::initialize(HeadRotation rot){
	HeadRotation tmp = init_matrix.vector_multi(arm->angle(0), arm->angle(1), arm->angle(2));
	rotation = rot - tmp;
}

HeadRotation ReferenceRotator::call(float x){
	return matrix.vector_multi(arm->angle(0), arm->angle(1), arm->angle(2));
}
