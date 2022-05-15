#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int arr[3];

	while (true) {
		cin >> arr[0] >> arr[1] >> arr[2];
		if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0) break;
		int maxVal = *max_element(arr, arr + 3);
		cout << ((maxVal*maxVal == arr[0] * arr[0] + arr[1] * arr[1] + arr[2] * arr[2] - maxVal * maxVal) ? "right" : "wrong") << endl;
	}
}