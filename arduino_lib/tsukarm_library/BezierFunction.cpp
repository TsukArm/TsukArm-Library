#include "BezierFunction.h"
#include "math.h"

BezierFunction::BezierFunction(CartesianPoint p2, CartesianPoint p3, CartesianPoint p4, bool abs, Stepper *s) : Function(s)
{
	points[1] = p2;
	points[2] = p3;
	points[3] = p4;
	is_absolute = abs;
}

void BezierFunction::initialize(CartesianPoint p1){
	if(is_absolute){
		points[0] = p1;
	}else{
		points[0] = CartesianPoint(0.0f, 0.0f, 0.0f);
		point = p1;
	}
}

CartesianPoint BezierFunction::call(float x){
	// 二項係数はわざわざ計算させるのも面倒なので配列で持つ。
	int facts[] = {1, 3, 3, 1};
	CartesianPoint result(0.0f, 0.0f, 0.0f);
	for(int i=0; i<4; i++){
		result = result + points[i].multi(facts[i] * pow(x, i) * pow(1-x, 3-i));
	}
	// 相対的であれば、基点座標と結果を足し合わせる
	if(!is_absolute){
		result = point + result;
	}
	return result;
}
