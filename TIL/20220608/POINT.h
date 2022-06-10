#ifndef _POINT_H
#define _POINT_H

#include <iostream>

using namespace std;

class POINT {
private:
	int x;
	int y;
public:
	POINT(const int _x = 0, const int _y = 0);
	POINT(const POINT& p);

	int getX();
	int getY();

	void setX(int _x);
	void setY(int _y);

	bool operator ==(const POINT& p);
	bool operator !=(const POINT& p);

	friend istream& operator >>(istream& in, POINT& p);
	friend ostream& operator <<(ostream& out, const POINT& p);
};

#else
#endif // _POINT_H