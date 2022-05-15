#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	bool check;
	vector<int> v;
	v.clear();

	for (int i = 0; i < 10; i++) {
		check = true;

		cin >> n;
		n %= 42;

		for (int& num : v) {
			if (num == n) {
				check = false;
				break;
			}
		}

		if (check) v.push_back(n);
	}

	cout << v.size();
}