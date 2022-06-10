#include "POINT.h"

POINT::POINT(const int _x, const int _y) {
	this->x = _x;
	this->y = _y;
}

POINT::POINT(const POINT& p) {
	this->x = p.x;
	this->y = p.y;
}

int POINT::getX() {
	return this->x;
}

int POINT::getY() {
	return this->y;
}

void POINT::setX(int _x) {
	this->x = _x;
}

void POINT::setY(int _y) {
	this->y = _y;
}

bool POINT::operator ==(const POINT& p) {
	return (this->x == p.x) && (this->y == p.y);
}

bool POINT::operator !=(const POINT& p) {
	return !((*this) == p);
}

istream& operator >>(istream& in, POINT& p) {
	return in >> p.x >> p.y;
}

ostream& operator <<(ostream& out, const POINT& p) {
	return out << "x: " << p.x << ", y: " << p.y << endl;
}