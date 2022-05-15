#include <iostream>
#include <string>
using namespace std;
char solve(string num) {
	for (int i = 0; i < num.length(); i++) {
		cout << num.at(i);
	}
	return 's';
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		string num;
		cin >> num;
		solve(num);
	}
	return 0;
}