#include <iostream>
using namespace std;

void drawer(int n) {
	int** arr = new int* [n];
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
	}

	if (n % 4 == 1) {
		for (int k = 0; k < (n + 1) / 2; k++) {
			for (int i = k; i < n - k; i++) {
				for (int j = k; j < n - k; j++) {
					arr[i][j] = (k % 2 == 0) ? 0 : 1;
				}
			}
		}
	}
	else {
		for (int k = 0; k < (n + 1) / 2; k++) {
			for (int i = k; i < n - k; i++) {
				for (int j = k; j < n - k; j++) {
					arr[i][j] = (k % 2 == 0) ? 1 : 0;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}

	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		drawer(n);
	}
}