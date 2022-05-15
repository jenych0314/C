#include <iostream>
using namespace std;

void solve(int n, int a, int b) {
	int** arr = new int* [n];
	int val = 0;

	// 값이 들어있는 2차원 배열을 그림
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = ++val;
		}
	}

	int size = b - a + 1, idx = 0;
	int x_idx = -1, y_idx = 0, step = n;
	int cnt = 0, cur;
	
	int* result = new int[size];
	
	// 시계방향으로 돌리기
	while (cnt < n * n) {
		for (int i = 0; i < step; i++) {
			cur = arr[y_idx][++x_idx];
			cnt++;
			if (a <= cnt && cnt <= b) {
				result[idx++] = cur;
			}
		}
		step--;
		if (cnt < n * n) {
			for (int i = 0; i < step; i++) {
				cur = arr[++y_idx][x_idx];
				cnt++;
				if (a <= cnt && cnt <= b) {
					result[idx++] = cur;
				}
			}
		}
		else break;
		for (int i = 0; i < step; i++) {
			cur = arr[y_idx][--x_idx];
			cnt++;
			if (a <= cnt && cnt <= b) {
				result[idx++] = cur;
			}
		}
		step--;
		for (int i = 0; i < step; i++) {
			cur = arr[--y_idx][x_idx];
			cnt++;
			if (a <= cnt && cnt <= b) {
				result[idx++] = cur;
			}
		}
	}

	// 답 출력
	for (int i = 0; i < size; i++) {
		cout << result[i] << " ";
	}
	cout << "\n";

	// 메모리 해제
	delete[] result;
	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n, a, b;
		cin >> n >> a >> b;
		solve(n, a, b);
	}
}