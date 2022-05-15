#include <iostream>
using namespace std;

int main() {
	/*double i;
	double* pd;

	pd = &i;
	*pd = 36.5;

	cout << i << endl;
	cout << &i << endl;
	cout << *pd << endl;
	cout << pd << endl;
	*/

	int i = 97;
	int* p;

	p = (int*)0x7fffffffde50;
	cout << "p: " << p << endl;
	p = &i;

	int* q = &i;

	cout << "p: " << p << endl;
	cout << "q: " << q << endl;
	cout << "sizeof(p): " << sizeof(p) << endl;
	cout << "sizeof(int*): " << sizeof(int*) << endl;

	cout << "i: " << i << endl;
	cout << "p: " << p << endl;
	cout << "q: " << q << endl;
	cout << "&i: " << &i << endl;

	return 0;
}