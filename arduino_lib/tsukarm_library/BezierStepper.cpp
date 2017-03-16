#include "BezierStepper.h"
#include "math.h"
#include "Arduino.h"

BezierStepper::BezierStepper(Square p2, Square p3, Square p4) : Stepper()
{
	points[0] = Square(0.0f, 0.0f);
	points[1] = p2;
	points[2] = p3;
	points[3] = p4;
}

BezierStepper::BezierStepper(Square p1, Square p2, Square p3, Square p4) : Stepper()
{
	points[0] = p1;
	points[1] = p2;
	points[2] = p3;
	points[3] = p4;
}

float BezierStepper::call(float t){
	// “ñ€ŒW”‚Í‚í‚´‚í‚´ŒvZ‚³‚¹‚é‚Ì‚à–Ê“|‚È‚Ì‚Å”z—ñ‚Å‚ÂB
	int facts[] = {1, 3, 3, 1};
	Square result(0.0f, 0.0f);
	for(int i=0; i<4; i++){
		result = result + points[i].multi(facts[i] * pow(t, i) * pow(1-t, 3-i));
	}
	return result.y();
}
