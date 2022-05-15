#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> arr) {
	int result = 0, size;
	size = arr.size();

	for (int i = 1; i < size - 1; i++) {
		if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
			result++;
		}
	}

	return result;
}

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int n;
		vector<int> arr;
		cin >> n;

		for (int j = 0; j < n; j++) {
			int elem;
			cin >> elem;

			if (arr.size() == 0) {
				arr.push_back(elem);
			}
			if (arr.back() != elem) {
				arr.push_back(elem);
			}
		}

		cout << solve(arr) << "\n";
	}
}