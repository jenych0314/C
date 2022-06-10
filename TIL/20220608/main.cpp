#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include "POINT.h"

using namespace std;

void swapV(int a, int b);
void swap(int& a, int& b);
void swap(int* a, int* b);

template <typename T>
class usingT {
public:
	static T sum(T num1, T num2);
};

template <class T> // <class T> == <typename T>
T usingT<T>::sum(T num1, T num2) {
	return num1 + num2;
}

int gcd(int a, int b);
int lcm(int a, int b);

int main() {
	//vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	//vector<int>::iterator it = v.begin(); // auto it = v.begin();

	//for (; it != v.end(); it++) {
	//	cout << *it << endl;
	//}

	//v.insert(v.begin(), 0);
	//v.insert(v.end(), 2, -2);

	//bind2nd(less<int>(), 5);

	/*set<int> mySet = { 2, 3, 5, 7, 11, 13, 17, 19 };
	auto iter = mySet.find(0);
	if (iter == mySet.end()) {
		cout << "no" << endl;
	}
	else {
		cout << *iter << endl;
	}
	mySet.insert(1);
	mySet.insert(-1);
	mySet.insert(-999);
	mySet.insert(80);
	mySet.insert(47);

	iter = mySet.begin();
	for (; iter != mySet.end(); ++iter) {
		cout << *iter << endl;
	}*/

	/*map<int, int> myMap;
	myMap.insert(1, 1);*/

	/*int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8 };
	sort(&arr[0], &arr[9]);
	for (int val : arr) {
		cout << val << endl;
	}*/

	POINT a(1, 2), b(2, 3), c(4, 5), d(6, 7);
	POINT e;
	cout << (e==a) << endl;
}

void swapV(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int gcd(int a, int b) {
	while (true) {
		int c = a % b;
		if (c == 0) return b;
		a = b;
		b = c;
	}
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}