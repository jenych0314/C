#ifndef _MYPOLYNOMIAL_H_
#define _MYPOLYNOMIAL_H_

#include <iostream>
#include <list>
#include "MyTerm.h"

using namespace std;

class myPolynomial : myTerm
{
public:
	myPolynomial(int c = 0, unsigned e = 0);
	myPolynomial(int nTerms, int mono[]);
	myPolynomial(int nTerms, myTerm terms[]);

	~myPolynomial();

	// copy constructor
	myPolynomial(const myPolynomial &poly);

	int getDegree() const;		  // get a degree of the polynomial
	unsigned getNumTerms() const; // number of terms in the polynomial

	void setCoeff(int idx, int c);

	myPolynomial ddx() const; // derivative of a polynomial

	myPolynomial operator+(const myPolynomial &poly) const;
	myPolynomial operator-(const myPolynomial &poly) const;
	myPolynomial operator*(const myPolynomial &poly) const;

	myPolynomial operator*(int k) const;

	friend myPolynomial operator*(int k, const myPolynomial &poly);

	long operator()(int x) const; // evaluate the polynomial

	myPolynomial operator-() const;

	// overloaded operators
	bool operator==(const myPolynomial &poly) const;
	bool operator!=(const myPolynomial &poly) const;

	myPolynomial &operator=(const myPolynomial &poly);
	myPolynomial &operator+=(const myPolynomial &poly);
	myPolynomial &operator-=(const myPolynomial &poly);
	myPolynomial &operator*=(const myPolynomial &poly);
	myPolynomial &operator*=(int k);

	// friend operators and functions
	friend myPolynomial operator*(int k, const myPolynomial &poly);
	friend ostream &operator<<(ostream &outStream, const myPolynomial &poly);

	static const myPolynomial ZERO; // P(x) = 0
	static const myPolynomial ONE;	// P(x) = 1
	static const myPolynomial X;	// P(x) = x
private:
	int degree; // maximum expnent
	int numTerms;
	myTerm *terms;
};

#endif _MYPOLYNOMIAL_H_