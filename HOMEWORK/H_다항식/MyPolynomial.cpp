#include "MyTerm.h"
#include "MyPolynomial.h"
#include <cmath>
#include <algorithm>
#include <vector>

myPolynomial::myPolynomial(int coeff, unsigned exp)
{
	this->degree = exp;	
	this->terms = new myTerm[1];
	(*this).terms[0] = myTerm(coeff, exp);
}

myPolynomial::myPolynomial(int nTerms, int mono[])
{
	this->numTerms = nTerms;

	(*this).terms = new myTerm[nTerms];
	for (int i = 0; i < nTerms; i++) {
		this->terms[i] = myTerm(mono[2 * i], mono[2 * i + 1]);
	}

	sort(this->terms, this->terms + nTerms);
	this->degree = this->terms[0].getExp();
}

myPolynomial::myPolynomial(int nTerms, myTerm arrTerms[])
{
	this->numTerms = nTerms;

	(*this).terms = new myTerm[nTerms];
	for (int i = 0; i < nTerms; i++) {
		this->terms[i] = arrTerms[i];
	}

	sort(this->terms, this->terms + nTerms);
	this->degree = this->terms[0].getExp();
}

myPolynomial::myPolynomial(vector<myTerm> v)
{
	int tNum = v.size();

	this->numTerms = tNum;

	(*this).terms = new myTerm[tNum];
	vector<myTerm>::iterator it;
	for (int i = 0; i < tNum; i++) {
		this->terms[i] = v.at(i);
	}

	sort(this->terms, this->terms + tNum);

	this->degree = this->terms[0].getExp();
}

myPolynomial::~myPolynomial()
{
	delete[] this->terms;
}

// copy constructor
myPolynomial::myPolynomial(const myPolynomial &poly)
{
	this->degree = poly.getDegree();
	this->numTerms = poly.getNumTerms();

	int pNum = poly.getNumTerms();
	(*this).terms = new myTerm[pNum];
	for (int i = 0; i < pNum; i++) {
		(*this).terms[i] = poly.terms[i];
	}
}

int myPolynomial::getDegree() const
{
	return this->degree;
}

unsigned myPolynomial::getNumTerms() const
{
	return this->numTerms;
}

myPolynomial myPolynomial::ddx() const
{
	int tNum = (*this).numTerms;

	myPolynomial newer;
	if (tNum == 1) {
		if ((*this).terms[0].exp == 0) {
			return myPolynomial::ZERO;
		}
		myTerm temp = (*this).terms[0].ddx();
		newer = myPolynomial(temp.getCoeff(), temp.getExp());
	}
	else {
		myTerm* temp = new myTerm[tNum - 1];
		for (int i = 0; i < tNum - 1; i++) {
			temp[i] = (*this).terms[i].ddx();
		}
		newer = myPolynomial(tNum - 1, temp);
		delete[] temp;
	}
	return newer;
}

myPolynomial myPolynomial::operator+(const myPolynomial &poly) const
{
	int tNum = (*this).numTerms, pNum = poly.getNumTerms();
	int left = 0, right = 0;
	vector<myTerm> v;
	while (left < tNum && right < pNum) {
		if ((*this).terms[left].exp > poly.terms[right].getExp()) {
			v.push_back(myTerm((*this).terms[left].coeff, (*this).terms[left].exp));
			left++;
		}
		else if ((*this).terms[left].exp == poly.terms[right].getExp()) {
			int coeff = (*this).terms[left].coeff + poly.terms[right].getCoeff();
			if (coeff != 0) {
				v.push_back(myTerm(coeff, (*this).terms[left].exp));
			}
			left++;
			right++;
		}
		else {
			v.push_back(myTerm(poly.terms[right].getCoeff(), poly.terms[right].getExp()));
			right++;
		}
	}
	for (; left < tNum; left++) {
		v.push_back(myTerm((*this).terms[left].coeff, (*this).terms[left].exp));
	}
	for (; right < pNum; right++) {
		v.push_back(myTerm(poly.terms[left].getCoeff(), poly.terms[left].getExp()));
	}

	bool isZero = true;
	for (myTerm val : v) {
		if (val.getCoeff() != 0) {
			isZero = false;
			break;
		}
	}

	if (isZero) {
		return myPolynomial::ZERO;
	}

	return myPolynomial(v);
}

myPolynomial myPolynomial::operator-(const myPolynomial &poly) const
{
	return (*this) + (-poly);
}

myPolynomial myPolynomial::operator*(const myPolynomial &poly) const
{
	int tNum = (*this).numTerms, pNum = poly.getNumTerms();

	myPolynomial result = myPolynomial::ZERO;
	for (int i = 0; i < tNum; i++) {
		myTerm* temp = new myTerm[pNum];
		for (int j = 0; j < pNum; j++) {
			int coeff = (*this).terms[i].coeff * poly.terms[j].getCoeff();
			int exp = (*this).terms[i].exp + poly.terms[j].getExp();
			temp[j] = myTerm(coeff, exp);
		}
		result += myPolynomial(pNum, temp);
		delete[] temp;
	}

	return result;
}

myPolynomial myPolynomial::operator*(int k) const
{
	int tNum = (*this).numTerms;

	myTerm* temp = new myTerm[tNum];
	for (int i = 0; i < tNum; i++) {
		int coeff = (*this).terms[i].coeff * k;
		int exp = (*this).terms[i].exp;
		temp[i] = myTerm(coeff, exp);
	}

	return myPolynomial(tNum, temp);
	delete[] temp;
}

myPolynomial operator*(int k, const myPolynomial &poly)
{
	return poly * k;
}

long myPolynomial::operator()(int x) const
{
	long result = 0;
	for (int i = 0; i < (*this).numTerms; i++) {
		result += (*this).terms[i].coeff * long(pow(x, (*this).terms[i].exp));
	}
	return result;
}

myPolynomial myPolynomial::operator-() const
{
	myPolynomial newer(*this);
	int nNum = newer.getNumTerms();
	for (int i = 0; i < nNum; i++) {
		int coeff = -newer.terms[i].getCoeff();
		newer.terms[i].setCoeff(coeff);
	}
	return newer;
}

// overloaded operators
bool myPolynomial::operator==(const myPolynomial &poly) const
{
	if ((*this).numTerms != poly.getNumTerms()) {
		return false;
	}
	for (int i = 0; i < (*this).numTerms; i++) {
		if (((*this).terms[i].coeff != poly.terms[i].getCoeff()) || ((*this).terms[i].exp != poly.terms[i].getExp())) {
			return false;
		}
	}
	return true;
}

bool myPolynomial::operator!=(const myPolynomial &poly) const
{
	return !((*this) == poly);
}

myPolynomial &myPolynomial::operator=(const myPolynomial &poly)
{
	(*this).degree = poly.getDegree();
	(*this).numTerms = poly.getNumTerms();
	delete[](*this).terms;

	int tNum = (*this).numTerms;
	(*this).terms = new myTerm[tNum];
	for (int i = 0; i < tNum; i++) {
		(*this).terms[i] = poly.terms[i];
	}

	return *this;
}

myPolynomial &myPolynomial::operator+=(const myPolynomial &poly)
{
	(*this) = (*this) + poly;
	return (*this);
}

myPolynomial &myPolynomial::operator-=(const myPolynomial &poly)
{
	(*this) = (*this) - poly;
	return (*this);
}

myPolynomial &myPolynomial::operator*=(const myPolynomial &poly)
{
	(*this) = (*this) * poly;
	return (*this);
}

myPolynomial &myPolynomial::operator*=(int k)
{
	(*this) = (*this) * k;
	return (*this);
}

// output operator
ostream &operator<<(ostream &outStream, const myPolynomial &poly)
{
	int pNum = poly.getNumTerms();
	if (pNum == 1) {
		if ((poly == myPolynomial::ZERO) || (poly.terms[0].getCoeff() == 0)) {
			return outStream << 0;
		}
	}
	
	if (poly.terms[0].getCoeff() != 0) {
		outStream << poly.terms[0];
	}
	else {
		outStream << 0;
	}
	for (int i = 1; i < pNum; i++) {
		int coeff = poly.terms[i].getCoeff();
		outStream << ((coeff > 0) ? "+" : ((coeff < 0) ? "" : ""));
		if (coeff != 0) {
			outStream << poly.terms[i];
		}
	}
	return outStream;
}

const myPolynomial myPolynomial::ZERO(0);			  // the zero polynomial P(x) = 0
const myPolynomial myPolynomial::ONE(1, (unsigned)0); // the monomial P(x) = 1
const myPolynomial myPolynomial::X(1, 1);			  // the monomial P(x) = x