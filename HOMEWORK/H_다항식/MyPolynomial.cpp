#include "MyTerm.h"
#include "MyPolynomial.h"
#include <cmath>
#include <algorithm>
#include <vector>

myPolynomial::myPolynomial(int coeff, unsigned exp)
{
	this->degree = exp;
	this->numTerms = 1;
	this->terms = new myTerm[this->numTerms];
	this->terms[0] = myTerm(coeff, exp);
}

myPolynomial::myPolynomial(int nTerms, int mono[])
{
	this->numTerms = nTerms;
	this->degree = mono[2 * nTerms - 1];

	this->terms = new myTerm[nTerms];
	for (int i = 0; i < nTerms; i++)
	{
		this->terms[i] = myTerm(mono[2 * i], mono[2 * i + 1]);
	}

	sort(this->terms, this->terms + nTerms);
}

myPolynomial::myPolynomial(int nTerms, myTerm arrTerms[])
{
	this->numTerms = nTerms;

	this->terms = new myTerm[nTerms];
	for (int i = 0; i < nTerms; i++)
	{
		this->terms[i] = arrTerms[i];
	}

	sort(this->terms, this->terms + nTerms);

	this->degree = this->terms[0].getExp();
}

myPolynomial::~myPolynomial()
{
	delete[] this->terms;
}

// copy constructor
myPolynomial::myPolynomial(const myPolynomial &poly)
{
	this->degree = poly.degree;
	this->numTerms = poly.numTerms;

	int size = poly.getNumTerms();
	this->terms = new myTerm[size];
	myTerm *pt = poly.terms;
	for (int i = 0; i < size; i++)
	{
		this->terms[i] = *pt++;
	}
}

int myPolynomial::getDegree() const
{
	if ((this->terms[0].getCoeff() == 0) && (this->terms[0].getExp() == 0))
		return -1;
	return this->terms[0].getExp();
}

unsigned myPolynomial::getNumTerms() const
{
	return this->numTerms;
}

void myPolynomial::setCoeff(int idx, int c)
{
	this->terms[idx].setCoeff(c);
}

myPolynomial myPolynomial::ddx() const
{
	int size = (*this).getNumTerms();

	myTerm *newTerms = new myTerm[size];
	myPolynomial newer;
	if (size == 1)
	{
		if ((*this).getDegree() == 0)
			return myPolynomial::ZERO;

		newTerms[0] = this->terms[0].ddx();
		newer = myPolynomial(size, newTerms);
	}
	else
	{
		for (int i = 0; i < size - 1; i++)
		{
			newTerms[i] = this->terms[i].ddx();
		}

		newer = myPolynomial(size - 1, newTerms);
	}
	return newer;
	delete[] newTerms;
}

myPolynomial myPolynomial::operator+(const myPolynomial &poly) const
{
	int coeff;
	int thisSize = (*this).getNumTerms(), polySize = poly.getNumTerms();
	int left = 0, right = 0;

	int maxDegree = max((*this).getDegree(), poly.getDegree());

	vector<myTerm> v;
	while (left < thisSize && right < polySize)
	{
		if (this->terms[left].exp > poly.terms[right].exp)
		{
			v.push_back(myTerm(this->terms[left].coeff, this->terms[left].exp));
			left++;
		}
		else if (this->terms[left].exp == poly.terms[right].exp)
		{
			coeff = this->terms[left].coeff + poly.terms[right].coeff;
			if (coeff != 0)
			{
				v.push_back(myTerm(coeff, this->terms[left].exp));
			}
			else
			{
				v.push_back(myTerm(0, this->terms[left].exp));
			}
			left++;
			right++;
		}
		else
		{
			v.push_back(myTerm(poly.terms[right].coeff, poly.terms[right].exp));
			right++;
		}
	}

	for (; left < thisSize; left++)
	{
		v.push_back(myTerm(this->terms[left].coeff, this->terms[left].exp));
	}
	for (; right < polySize; right++)
	{
		v.push_back(myTerm(poly.terms[right].coeff, poly.terms[right].exp));
	}

	int vSize = v.size();
	bool isZero = true;
	myTerm *newTerms = new myTerm[vSize];
	for (int i = 0; i < vSize; i++)
	{
		newTerms[i] = v.at(i);

		if (v.at(i).getCoeff() != 0)
			isZero = false;
	}

	if (isZero)
		return myPolynomial::ZERO;

	return myPolynomial(vSize, newTerms);
	delete[] newTerms;
}

myPolynomial myPolynomial::operator-(const myPolynomial &poly) const
{
	return (*this) + (-poly);
}

myPolynomial myPolynomial::operator*(const myPolynomial &poly) const
{
	int thisSize = (*this).getNumTerms(), polySize = poly.getNumTerms();

	myPolynomial *newPolys = new myPolynomial[thisSize];
	for (int i = 0; i < thisSize; i++)
	{
		myTerm *newTerms = new myTerm[polySize];

		for (int j = 0; j < polySize; j++)
		{
			int coeff = this->terms[i].getCoeff() * poly.terms[j].getCoeff();
			int exp = this->terms[i].getExp() + poly.terms[j].getExp();
			newTerms[j] = myTerm(coeff, exp);
		}

		newPolys[i] = myPolynomial(polySize, newTerms);
		delete[] newTerms;
	}

	myPolynomial result(newPolys[0]);
	for (int i = 1; i < thisSize; i++)
	{
		result += newPolys[i];
	}

	return result;
	delete[] newPolys;
}

myPolynomial myPolynomial::operator*(int k) const
{
	return (*this) * myPolynomial(k, unsigned(0));
}

myPolynomial operator*(int k, const myPolynomial &poly)
{
	return myPolynomial(k, unsigned(0)) * poly;
}

long myPolynomial::operator()(int x) const
{
	int size = (*this).getNumTerms();
	long result = 0;

	for (int i = 0; i < size; i++)
	{
		result += (this->terms[i].coeff) * (long)pow(x, this->terms[i].exp);
	}

	return result;
}

myPolynomial myPolynomial::operator-() const
{
	int size = (*this).getNumTerms();

	myPolynomial poly = (*this);
	for (int i = 0; i < size; i++)
	{
		poly.terms[i].coeff *= -1;
	}

	return poly;
}

// overloaded operators
bool myPolynomial::operator==(const myPolynomial &poly) const
{
	if ((poly.getDegree() != (*this).getDegree()) || (poly.getNumTerms() != (*this).getNumTerms()))
		return false;

	int size = (*this).getNumTerms();
	for (int i = 0; i < size; i++)
	{
		if (this->terms[i] != poly.terms[i])
			return false;
	}

	return true;
}

bool myPolynomial::operator!=(const myPolynomial &poly) const
{
	return !((*this) == poly);
}

myPolynomial &myPolynomial::operator=(const myPolynomial &poly)
{
	int polySize = poly.getNumTerms();

	this->terms = new myTerm[polySize];
	this->numTerms = poly.getNumTerms();
	this->degree = poly.getDegree();

	for (int i = 0; i < polySize; i++)
	{
		this->terms[i] = myTerm(poly.terms[i].getCoeff(), poly.terms[i].getExp());
	}

	return (*this);
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
	if (poly == myPolynomial::ZERO)
		return outStream << 0;

	int size = poly.getNumTerms();

	if (size == 1)
	{
		if (poly.terms[0].getCoeff() == 0)
			return outStream << 0;

		return outStream << poly.terms[0];
	}
	else
	{
		for (int i = 0; i < size - 1; i++)
		{
			if (!(poly.terms[i].getCoeff() == 0))
				outStream << poly.terms[i];

			if (!(poly.terms[i + 1].getCoeff() <= 0))
				outStream << "+";
		}

		if (!(poly.terms[size - 1].getCoeff() == 0))
		{
			outStream << poly.terms[size - 1];
		}

		return outStream;
	}
}

const myPolynomial myPolynomial::ZERO(0);			  // the zero polynomial P(x) = 0
const myPolynomial myPolynomial::ONE(1, (unsigned)0); // the monomial P(x) = 1
const myPolynomial myPolynomial::X(1, 1);			  // the monomial P(x) = x