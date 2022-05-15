#include <iostream>
using namespace std;

int main() {
	int i = 97;
	int* p;

	p = (int*)0x7fffffffde50;
	cout << "p: " << p << endl;
	//cout << "*p: " << *p << endl;

	p = &i;

	int* q = &i;

	cout << "p: " << p << endl;
	cout << "q: " << q << endl;
	cout << "sizeof(p): " << sizeof(p) << endl;
	cout << "sizeof(int*): " << sizeof(int*) << endl;

	cout << "i: " << i << endl;
	cout << "*p: " << * p << endl;
	cout << "*q: " << * q << endl;
	cout << "&i: " << & i << endl;

	char c = 'a';

	char* ptr;
	ptr = &c;

	cout << "sizeof(char*): " << sizeof(char*) << endl;

	float f = 97;

	float* f_p;
	int* i_p;

	f_p = &f;
	cout << "*f_p: " << *f_p << endl;

	i_p = (int*)&f;
	cout << "*i_p: " << *i_p << endl;
}