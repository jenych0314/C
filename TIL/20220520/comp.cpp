#include "MyComplex.h"
// 생성자
myComplex::myComplex(int real, int imag)
{
    realPart = real;
    imaginaryPart = imag;
}

// 복사 생성자
myComplex::myComplex(const myComplex &number)
{
    realPart = number.realPart;
    imaginaryPart = number.imaginaryPart;
}

// 접근자
int myComplex::getRealPart() const
{
    return realPart;
}

int myComplex::getImaginaryPart() const
{
    return imaginaryPart;
}

// 변경자
void myComplex::setRealPart(int real)
{
    realPart = real;
}

void myComplex::setImaginaryPart(int imag)
{
    imaginaryPart = imag;
}

void myComplex::set(int real, int imag)
{
    realPart = real;
    imaginaryPart = imag;
}

// Overloaded binary operators
myComplex myComplex::operator+(const myComplex &number) const
{
    int newReal = realPart + number.realPart;
    int newImag = imaginaryPart + number.imaginaryPart;
    return myComplex(newReal, newImag);
}

myComplex myComplex::operator-(const myComplex &number) const
{
    int newReal = realPart - number.realPart;
    int newImag = imaginaryPart - number.imaginaryPart;
    return myComplex(newReal, newImag);
}

myComplex myComplex::operator*(const myComplex &number) const
{
    int newReal = (realPart * number.realPart) - (imaginaryPart * number.imaginaryPart);
    int newImag = (realPart * number.imaginaryPart) + (imaginaryPart * number.realPart);
    return myComplex(newReal, newImag);
}

// myComplex myComplex::operator +(int value) const
// {
//     return myComplex(value) + (*this);
// }

// myComplex myComplex::operator -(int value) const
// {
//     return myComplex(value) - (*this);
// }

// myComplex myComplex::operator *(int value) const
// {
//     return myComplex(value) * (*this);
// }

// Assignment operators =, +=, -=, *=
myComplex &myComplex::operator=(const myComplex &number)
{
    this->realPart = number.realPart;
    this->imaginaryPart = number.imaginaryPart;
    return *this;
}

myComplex &myComplex::operator=(int value)
{
    realPart = value;
    imaginaryPart = 0;
    return *this;
}

myComplex &myComplex::operator+=(const myComplex &number)
{
    (*this) = (*this) + number;
    return (*this);
}

myComplex &myComplex::operator-=(const myComplex &number)
{
    (*this) = (*this) - number;
    return (*this);
}

myComplex &myComplex::operator*=(const myComplex &number)
{
    (*this) = (*this) * number;
    return (*this);
}

// Overloading comparison operators
bool myComplex::operator==(const myComplex &number) const
{
    return (realPart == number.realPart) && (imaginaryPart == number.imaginaryPart);
}

bool myComplex::operator!=(const myComplex &number) const
{
    return !(realPart == number.realPart) || !(imaginaryPart == number.imaginaryPart);
}

bool myComplex::operator>(const myComplex &number) const
{
    return norm() > number.norm();
}

bool myComplex::operator>=(const myComplex &number) const
{
    return norm() >= number.norm();
}

bool myComplex::operator<(const myComplex &number) const
{
    return norm() < number.norm();
}

bool myComplex::operator<=(const myComplex &number) const
{
    return norm() <= number.norm();
}

// Overloaded unary operators
myComplex myComplex::operator-() // unary minus
{
    return myComplex(-realPart, -imaginaryPart);
}

myComplex myComplex::operator~()
{
    return myComplex(realPart, -imaginaryPart);
}

// ++ -- 전위 후위
myComplex &myComplex::operator++()
{
    realPart++;
    return (*this);
}

myComplex myComplex::operator++(int)
{
    myComplex temp(*this);
    realPart += 1;
    return (temp);
}

myComplex &myComplex::operator--()
{
    realPart--;
    return (*this);
}

myComplex myComplex::operator--(int)
{
    myComplex temp(*this);
    realPart -= 1;
    return (temp);
}

// // 객체 + 상수
myComplex myComplex::operator+(int value)
{
    return myComplex(realPart + value, imaginaryPart);
}

myComplex myComplex::operator-(int value)
{
    return myComplex(realPart - value, imaginaryPart);
}

myComplex myComplex::operator*(int value)
{
    return myComplex(realPart * value, imaginaryPart * value);
}

// 상수 + 객체
myComplex operator+(int value, const myComplex &number)
{
    myComplex tmp(value + number.realPart, number.imaginaryPart);
    return tmp;
}

myComplex operator-(int value, const myComplex &number)
{
    myComplex tmp(value - number.realPart, -number.imaginaryPart);
    return tmp;
}

myComplex operator*(int value, const myComplex &number)
{
    myComplex tmp(value * number.realPart, value * number.imaginaryPart);
    return tmp;
}

// private function
int myComplex::norm() const
{
    return realPart * realPart + imaginaryPart * imaginaryPart;
}

ostream &operator<<(ostream &outStream, const myComplex &number)
{
    outStream << "(" << number.realPart << "," << number.imaginaryPart << ")";
    return outStream;
}

istream &operator>>(istream &inStream, myComplex &number)
{
    inStream >> number.realPart >> number.imaginaryPart;
    return inStream;
}