#include <iostream>
#include <math.h>
using namespace std;

bool checker(int num) {
	double k = log10(num);
	k = int(k) + 1;
	int d = 0, n = num;
	double sum = 0;

	for (int i = 0; i < k; i++) {
		d = n % 10;
		sum += pow(d, k);
		n /= 10;
	}

	return int(sum) == num;
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		bool result = checker(n);

		cout << (result) ? 1 : 0;
		cout << endl;
	}
}