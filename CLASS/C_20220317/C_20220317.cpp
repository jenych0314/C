#include <iostream>
using namespace std;

int main() {
	int t;

	cin >> t;

	for (int i = 0; i < t; i++) {
		int n, nums;
		int sum = 0;

		cin >> n;
		
		for (int j = 0; j < n; j++) {
			cin >> nums;
			sum += nums;
		}

		cout << sum << endl;
	}

	return 0;
}