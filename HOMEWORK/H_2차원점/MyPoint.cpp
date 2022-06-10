#include <cstdlib>
#include "MyPoint.h"
#include <cmath>

// constructors
MyPoint::MyPoint() : x(this->x = 0), y(this->y = 0) {}

MyPoint::MyPoint(int coordX, int coordY)
{
	this->x = coordX;
	this->y = coordY;
}

MyPoint::MyPoint(const MyPoint &p)
{
	this->x = p.x;
	this->y = p.y;
}

// accessor functions
int MyPoint::getX() const
{
	return this->x;
}

int MyPoint::getY() const
{
	return this->y;
}

// mutator functions
void MyPoint::setX(int coordX)
{
	this->x = coordX;
}

void MyPoint::setY(int coordY)
{
	this->y = coordY;
}

bool MyPoint::operator==(const MyPoint &p) const
{
	return (this->x == p.x) && (this->y == p.y);
}

bool MyPoint::operator!=(const MyPoint &p) const
{
	return !operator==(p);
}

int MyPoint::dist2sqr(const MyPoint &p) const
{
	return (this->x - p.x) * (this->x - p.x) + (this->y - p.y) * (this->y - p.y);
}

int MyPoint::dist1(const MyPoint &p) const
{
	return abs(this->x - p.x) + abs(this->y - p.y);
}