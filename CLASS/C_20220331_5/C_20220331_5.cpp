#include <iostream>
#include <string>
using namespace std;

// ������ ��� �ڸ��� �ݺ� ���ϱ�

string solve(string num) {
	while (num.length() > 1) {
		int n = 0, multi = 1;
		for (int i = 0; i < num.length(); i++) {
			if (num.at(i) == '0') continue;
			n = (int)num.at(i) - 48; // �ƽ�Ű�ڵ�� ���
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