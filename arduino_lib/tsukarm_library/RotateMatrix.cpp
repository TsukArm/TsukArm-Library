#include "RotateMatrix.h"

RotateMatrix::RotateMatrix(float* c){
	for(int i=0; i<12; i++){
		cell[i] = c[i];
	}
}

RotateMatrix::RotateMatrix(){
	for(int i=0; i<12; i++){
		cell[i] = 0;
	}

}

RotateMatrix::RotateMatrix(float a11, float a12, float a13, float a14, float a21, float a22, float a23, float a24, float a31, float a32, float a33, float a34){
	int temp[] = {a11, a12, a13, a14, a21, a22, a23, a24, a31, a32, a33, a34};
	for(int i=0; i<12; i++){
		cell[i] = temp[i];
	}
}

RotateMatrix::RotateMatrix(HeadRotation r1, HeadRotation r2, HeadRotation r3, HeadRotation r4){
	cell[0] = r1.roll().toRad();
	cell[1] = r2.roll().toRad();
	cell[2] = r3.roll().toRad();
	cell[3] = r4.roll().toRad();
	cell[4] = r1.pitch().toRad();
	cell[5] = r2.pitch().toRad();
	cell[6] = r3.pitch().toRad();
	cell[7] = r4.pitch().toRad();
	cell[8] = r1.yaw().toRad();
	cell[9] = r2.yaw().toRad();
	cell[10] = r3.yaw().toRad();
	cell[11] = r4.yaw().toRad();
}

void RotateMatrix::set(int i, float v){
	cell[i] = v;
}

const HeadRotation RotateMatrix::vector_multi(const Angle v1, const Angle v2, const Angle v3) const {
	return HeadRotation(
		v1.multi(cell[0]) + v2.multi(cell[1]) + v3.multi(cell[2]) + Angle::deg(1.0f).multi(cell[3]),
		v1.multi(cell[4]) + v2.multi(cell[5]) + v3.multi(cell[6]) + Angle::deg(1.0f).multi(cell[7]),
		v1.multi(cell[8]) + v2.multi(cell[9]) + v3.multi(cell[10]) + Angle::deg(1.0f).multi(cell[11])
	);
}
