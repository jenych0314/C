#include <iostream>
using namespace std;

int main() {
	int n, x, temp;
	cin >> n >> x;
	//int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp < x) cout << temp << " ";
	}
}