#include <iostream>
#include <format>
using namespace std;
// 세 개의 정수 정렬
void sort3Int(int a, int b, int c) {
	if (a <= b) {
		if (b <= c) {
			cout << a << " " << b << " " << c << endl;
		}
		else if (a <= c) {
			cout << a << " " << c << " " << b << endl;
		}
		else {
			cout << c << " " << a << " " << b << endl;
		}
	}
	else {
		if (a <= c) {
			cout << b << " " << a << " " << c << endl;
		}
		else if (b <= c) {
			cout << b << " " << c << " " << a << endl;
		}
		else {
			cout << c << " " << b << " " << a << endl;
		}
	}
}

string sort3Integer(int a, int b, int c) {
	// 삼항 연산자와 스트링 포맷팅을 이용하면 코드를 엄청 줄일 수 있을 듯
	string result;

	if (a <= b) {
		result = (b <= c) ? a, b, c : (a <= c) ? a, c, b : c, a, b;
		/*if (b <= c) {
			cout << a << " " << b << " " << c << endl;
		}
		else if (a <= c) {
			cout << a << " " << c << " " << b << endl;
		}
		else {
			cout << c << " " << a << " " << b << endl;
		}
		*/
	}
	else {
		result = (a <= c) ? a, b, c : (b <= c) ? a, c, b : c, a, b;
		/*
		if (a <= c) {
			cout << b << " " << a << " " << c << endl;
		}
		else if (b <= c) {
			cout << b << " " << c << " " << a << endl;
		}
		else {
			cout << c << " " << b << " " << a << endl;
		}
		*/
	}

	return result;
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		sort3Int(a, b, c);
		cout << sort3Integer(a, b, c);
	}

	return 0;
}