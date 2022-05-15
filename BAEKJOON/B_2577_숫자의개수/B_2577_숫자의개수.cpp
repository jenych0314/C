#include <iostream>
#include <string>

using namespace std;

int main() {
	int a, b, c;
	int arr[10] = {};

	cin >> a >> b >> c;
	string str = to_string(a * b * c);

	for (char& c : str) {
		int idx = c - '0';
		arr[idx]++;
	}

	for (int& n : arr) {
		cout << n << "\n";
	}
}