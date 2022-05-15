#include <iostream>
#include <vector>

using namespace std;

int main() {
	string str;
	cin >> str;

	vector<int> v(26, 0);
	for (char& c : str) {
		int idx = (c - 'a' >= 0) ? c - 'a' : c - 'A';
		v[idx]++;
	}

	int max = 0, max_idx;
	for (int i = 0; i < 26; i++) {
		if (v[i] > max) {
			max = v[i];
			max_idx = i;
		}
	}

	int cnt = 0;
	for (int& elem : v) {
		if (elem == max) {
			cnt++;
		}
	}

	cout << ((cnt == 1) ? char(65 + max_idx) : '?');
}