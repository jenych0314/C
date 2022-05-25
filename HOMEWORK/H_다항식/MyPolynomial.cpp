#include "MyTerm.h"
#include "MyPolynomial.h"

/********************* add your code here ********************************/
myPolynomial::myPolynomial(int c = 0, unsigned e = 0)
{
	this->degree = e;
	myTerm(c, e);
}

myPolynomial::myPolynomial(int nTerms, int mono[])
{
	this->degree = nTerms - 1;
	for (int i = 0; i < nTerms; i++) {
		myTerm(mono[i], mono[i + 1]);
	}
}

// copy constructor
myPolynomial::myPolynomial(const myPolynomial& poly)
{
	this->degree = poly.degree;
	for (int i = 0; i < degree; i++) {
		//this->term = poly.term;
	}
}

// overloaded operators
bool myPolynomial::operator == (const myPolynomial& poly) const
{
	
}

bool myPolynomial::operator != (const myPolynomial& poly) const
{
	return !((*this) == poly);
}

myPolynomial& myPolynomial::operator += (const myPolynomial& poly)
{

}
myPolynomial& myPolynomial::operator -= (const myPolynomial& poly)
{

}
myPolynomial& myPolynomial::operator *= (const myPolynomial& poly)
{

}
myPolynomial& myPolynomial::operator *= (int k)
{

}

myPolynomial myPolynomial::operator -() const
{

}
myPolynomial myPolynomial::operator *(int k) const
{

}
myPolynomial myPolynomial::operator +(const myPolynomial& poly) const
{

}
myPolynomial myPolynomial::operator -(const myPolynomial& poly) const
{

}
myPolynomial myPolynomial::operator *(const myPolynomial& poly) const
{

}

long myPolynomial::operator() (int x) const
{

}

int myPolynomial::getDegree() const
{
	return this->degree;
}
unsigned myPolynomial::getNumTerms() const
{
	
}

myPolynomial myPolynomial::ddx() const
{

}

// friend operators and functions
myPolynomial operator *(int k, const myPolynomial& poly)
{

}

// output operator
ostream& operator <<(ostream& outStream, const myPolynomial& poly)
{
	if (poly == myPolynomial::ZERO)
		return outStream << 0;
	/********************* add your code here ********************************/
	return outStream;
}

const myPolynomial myPolynomial::ZERO(0); // the zero polynomial P(x) = 0
const myPolynomial myPolynomial::ONE(1, (unsigned)0); // the monomial P(x) = 1
const myPolynomial myPolynomial::X(1, 1); // the monomial P(x) = x`