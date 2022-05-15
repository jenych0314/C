#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, max, cnt = 1, idx = 1;

	cin >> n;
	max = n;
	cnt++;

	for (int i = 0; i < 8; i++) {
		cin >> n;
		if (n > max) {
			max = n;
			idx = cnt;
		}
		cnt++;
	}

	cout << max << "\n" << idx << "\n";
}