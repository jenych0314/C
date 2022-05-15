#include <iostream>
#include <string>
using namespace std;

// 숫자의 모든 자릿수 반복 곱하기

string solve(string num) {
	while (num.length() > 1) {
		int n = 0, multi = 1;
		for (int i = 0; i < num.length(); i++) {
			if (num.at(i) == '0') continue;
			n = (int)num.at(i) - 48; // 아스키코드로 계산
			multi *= n;
		}
		num = to_string(multi);
	}
	return num;
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		string num;
		cin >> num;
		cout << solve(num) << endl;
	}
}