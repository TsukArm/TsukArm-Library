#include "Square.h"

Square::Square(float _x, float _y){
	mx = _x;
	my = _y;
}

const Square Square::multi(const float n) const {
	return Square(
		mx * n,
		my * n
	);
}

const Square Square::operator+(const Square c) const {
	return Square(
		mx + c.mx,
		my + c.my
	);
}

const Square Square::operator-(const Square c) const {
	return Square(
		mx - c.mx,
		my - c.my
	);
}
