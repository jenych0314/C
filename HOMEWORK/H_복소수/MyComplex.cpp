#include "MyComplex.h"

// Constructor
myComplex::myComplex(int real, int imag)
{
	this->realPart = real;
	this->imaginaryPart = imag;
}

// Copy constructor
myComplex::myComplex(const myComplex& number)
{
	this->realPart = number.realPart;
	this->imaginaryPart = number.imaginaryPart;
}

// Accessor functions
int myComplex::getRealPart() const
{
	return this->realPart;
}

int myComplex::getImaginaryPart() const
{
	return this->imaginaryPart;
}

// Mutator functions
void myComplex::setRealPart(int real)
{
	this->realPart = real;
}

void myComplex::setImaginaryPart(int imag)
{
	this->imaginaryPart = imag;
}

void myComplex::set(int real, int imag)
{
	this->realPart = real;
	this->imaginaryPart = imag;
}

// Overloaded arithmetic operators
myComplex myComplex::operator + (const myComplex& number) const
{
	int newReal = this->realPart + number.realPart;
	int newImag = this->imaginaryPart + number.imaginaryPart;
	return myComplex(newReal, newImag);
}

myComplex myComplex::operator + (int value)
{
	return myComplex(value) + (*this);
}

myComplex operator + (int value, const myComplex& number)
{
	return myComplex(value) + number;
}

myComplex myComplex::operator - (const myComplex& number) const
{
	int newReal = this->realPart - number.realPart;
	int newImag = this->imaginaryPart - number.imaginaryPart;
	return myComplex(newReal, newImag);
}

myComplex myComplex::operator - (int value)
{
	return (*this) - myComplex(value);
}

myComplex operator - (int value, const myComplex& number)
{
	return myComplex(value) - number;
}

myComplex myComplex::operator * (const myComplex& number) const
{
	int newReal = this->realPart * number.realPart - this->imaginaryPart * number.imaginaryPart;
	int newImag = this->realPart * number.imaginaryPart + this->imaginaryPart * number.realPart;
	return myComplex(newReal, newImag);
}

myComplex myComplex::operator * (int value)
{
	return myComplex(value) * (*this);
}

myComplex operator * (int value, const myComplex& number)
{
	return myComplex(value) * number;
}

// Assignment operators
myComplex& myComplex::operator = (const myComplex& number)
{
	this->realPart = number.realPart;
	this->imaginaryPart = number.imaginaryPart;
	return *this;
}

myComplex& myComplex::operator = (int value)
{
	(*this) = myComplex(value);
	return *this;
}

myComplex& myComplex::operator += (const myComplex& number)
{
	(*this) = (*this) + number;
	return *this;
}

myComplex& myComplex::operator -= (const myComplex& number)
{
	(*this) = (*this) - number;
	return *this;
}

myComplex& myComplex::operator *= (const myComplex& number)
{
	(*this) = (*this) * number;
	return *this;
}

// Overloading comparison operators
bool myComplex::operator == (const myComplex& number) const
{
	return (this->realPart == number.realPart) &&
		(this->imaginaryPart == number.imaginaryPart);
}

bool myComplex::operator != (const myComplex& number) const
{
	return !((*this) == number);
}

bool myComplex::operator > (const myComplex& number) const
{
	return this->norm() > number.norm();
}

bool myComplex::operator < (const myComplex& number) const
{
	return this->norm() < number.norm();
}

bool myComplex::operator >= (const myComplex& number) const
{
	return this->norm() >= number.norm();
}

bool myComplex::operator <= (const myComplex& number) const
{
	return this->norm() <= number.norm();
}

myComplex myComplex::operator -()
{
	return myComplex(-this->realPart, -this->imaginaryPart);
}

myComplex myComplex::operator ~()
{
	return myComplex(this->realPart, -this->imaginaryPart);
}

myComplex &myComplex::operator ++()
{
	this->realPart++;
	return *this;
}

myComplex myComplex::operator ++(int)
{
	myComplex tmp(*this);
	operator++();
	return tmp;
}

myComplex &myComplex::operator --()
{
	this->realPart--;
	return *this;
}

myComplex myComplex::operator --(int)
{
	myComplex tmp(*this);
	operator--();
	return tmp;
}

// private function
int myComplex::norm() const
{
	return this->realPart * this->realPart + this->imaginaryPart * this->imaginaryPart;
}

ostream& operator << (ostream& outStream, const myComplex& number)
{
	outStream << "(" << number.getRealPart() << "," << number.getImaginaryPart() << ")";

	return outStream;
}

istream& operator >> (istream& inStream, myComplex& number)
{
	inStream >> number.realPart >> number.imaginaryPart;

	return inStream;
}
