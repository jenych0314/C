#include <iostream>

using namespace std;

void solve(int cnt);

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		solve(n);
	}
}

void solve(int cnt) {
	// 오셀로판 초기화
	char** arr = new char* [8];
	for (int i = 0; i < 8; i++) {
		arr[i] = new char[8]{ '+', '+', '+' , '+' , '+' , '+' , '+' , '+' };
	}
	arr[3][3] = arr[4][4] = 'O';
	arr[3][4] = arr[4][3] = 'X';


	for (int i = 0; i < cnt; i++) {
		int xIdx, yIdx;
		cin >> xIdx >> yIdx;
		// 배열의 좌표값의 맞춤.
		xIdx--;
		yIdx--;

		char piece = (i % 2 == 0) ? 'X' : 'O';
		arr[yIdx][xIdx] = piece;
		int direction[8][2] = { {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1,-1}, {-1, 0}, {-1, 1} }; // 진행할 방향의 증감값을 담고 있는 배열 (x, y)
		for (int i = 0; i < 8; i++) {
			int path[8][2] = { {-1, -1}, {-1, -1} , {-1, -1} , {-1, -1} , {-1, -1} , {-1, -1} , {-1, -1} , {-1, -1} }; // 현재 piece와 다른 piece를 발견할 경우 지나간 경로를 기억할 배열 (x, y)
			int currX = xIdx + direction[i][0], currY = yIdx + direction[i][1]; // 현재 지나가고 있는 경로의 좌표
			bool check = false; // 같은 piecd를 만났는지 여부 판단
			int pathCnt = 0; // path의 들어간 개수
			while ((0 <= currX && currX <= 7) && (0 <= currY && currY <= 7)) { // 현재 좌표가 오셀로 판 내부의 있을 때
				if (arr[currY][currX] == '+') // 빈 칸일 경우
					break;
				else if (arr[currY][currX] == piece) { // 현재 piece와 같은 piece일 경우
					check = true;
					break;
				}
				else { // 현재 piece와 다른 piece일 경우
					// path에 (currX, currY) 추가
					path[pathCnt][0] = currX;
					path[pathCnt][1] = currY;
					pathCnt++;

					// 현재 진행 방향으로 currX, currY 증감
					currX += direction[i][0];
					currY += direction[i][1];
				}
			}
			if (check) { // 현재 piece와 같은 piece를 만났을 때
				for (int i = 0; i < 8; i++) {
					if (path[i][0] == -1 || path[i][1] == -1) // 지나간 경로가 아닐 경우 종료
						break;
					arr[path[i][1]][path[i][0]] = piece; // 지나간 경로일 경우 현재 piece 모양으로 변경.
				}
			}
		}
	}

	// 검은 돌, 흰 돌 개수 세기
	int white = 0, black = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (arr[i][j] == 'O')
				white++;
			if (arr[i][j] == 'X')
				black++;
		}
	}

	// 답안 출력
	cout << black << " " << white << "\n";
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << arr[j][i];
		}
		cout << "\n";
	}

	for (int i = 0; i < 8; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}