#ifndef _MYTERM_H_
#define _MYTERM_H_

#include <iostream>

using namespace std;

class myPolynomial;
class myTerm
{
public:
	myTerm(int c = 0, unsigned e = 0);

	// copy constructor
	myTerm(const myTerm &term);

	// accessor functions
	int getCoeff() const { return this->coeff; }
	unsigned getExp() const { return this->exp; }

	// mutator functions
	void setCoeff(int c) { this->coeff = c; }
	void setExp(unsigned e) { this->exp = e; }

	// member functions
	myTerm ddx() const; // derivative of a term

	// overloaded operators
	bool operator==(const myTerm &term) const;
	bool operator!=(const myTerm &term) const;
	bool operator<(const myTerm &term) const;
	myTerm operator-() const;

	// friend functions and classes
	friend ostream &operator<<(ostream &outStream, const myTerm &term);
	friend myPolynomial;

private:
	int coeff;		  // integer coefficient
	unsigned int exp; // exponent (non-negative integer)
};

#endif _MYTERM_H_