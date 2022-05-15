#include <iostream>
using namespace std;

int main() {
	int n, max, min, temp;
	cin >> n;

	cin >> temp;

	max = min = temp;
	for (int i = 0; i < n - 1; i++) {
		cin >> temp;
		if (temp > max) max = temp;
		if (temp < min) min = temp;
	}

	cout << min << " " << max;
}