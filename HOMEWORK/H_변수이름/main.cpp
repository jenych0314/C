#include <iostream>
#include <string>

using namespace std;

int solve(string name) {
	int stringLength = name.length();
	if (isdigit(name.front())) return 0;
	else {
		for (char c : name) {
			if (!isalnum(c) && c != '_') return 0;
		}
		return 1;
	}
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		string name;
		cin >> name;
		cout << solve(name) << endl;
	}
}