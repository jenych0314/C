#include <iostream>
using namespace std;
// 주어진 정수들 최대 최소 구하기
int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int C, n, max_num, min_num;
		cin >> C;

		cin >> n;
		max_num = min_num = n;

		for (int j = 1; j < C; j++) {
			cin >> n;
			if (n > max_num) {
				max_num = n;
			}
			if (n < min_num) {
				min_num = n;
			}
		}

		cout << max_num << " " << min_num << endl;
	}

	return 0;
}