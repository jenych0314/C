#include <iostream>

using namespace std;

void solve(int n) {
	char** arr = new char* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new char[n];
	}

	// 1. . 채운다
	// 2. -, |, \, / 채운다
	// 3. + 채운다
	// 4. * 채운다
	for (int i = 0; i < n; i++) {
		bool row = false;
		if (i == 0 || i == n - 1 || i == (n - 1) / 2) row = true;
		for (int j = 0; j < n; j++) {
			bool col = false, upward = false, downward = false;

			if (j == 0 || j == n - 1 || j == (n - 1) / 2) col = true;
			if (i == j) downward = true;
			if (i + j == n - 1) upward = true;

			arr[i][j] = '.';

			if (row) arr[i][j] = '-';
			else if (col) arr[i][j] = '|';
			else if (upward) arr[i][j] = '/';
			else if (downward) arr[i][j] = '\\';

			if (row && col) arr[i][j] = '+';

			if (row && col && upward && downward) arr[i][j] = '*';
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}

	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}

int main() {
	int T, n;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> n;
		solve(n);
	}
}