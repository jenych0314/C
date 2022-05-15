#include <iostream>
#include <string>

using namespace std;

int solve(string str) {
	int result = 0, score = 1;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'O') {
			result += score++;
		}
		else {
			score = 1;
		}
	}

	return result;
}

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		string str;
		cin >> str;
		cout << solve(str) << "\n";
	}
}