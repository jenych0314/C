#include <iostream>
#include <vector>

using namespace std;

int solveL(int arr1[2][2], int arr2[2][2]) {
	int X = 0, Y = 0, L;

	// X
	if (X == 0) {
		if (arr1[1][0] < arr2[0][0] || arr2[1][0] < arr1[0][0]) { // 떨어져있을 때
			X = (arr1[1][0] - arr1[0][0]) + (arr2[1][0] - arr2[0][0]);
			Y = (arr1[1][1] - arr1[0][1]) + (arr2[1][1] - arr2[0][1]);
		}
		else if (arr1[0][0] < arr2[0][0] && arr2[0][0] < arr1[1][0] && arr1[1][0] < arr2[1][0]) { // 겹쳐져 있을 때 1
			X = arr2[1][0] - arr1[0][0];
		}
		else if (arr2[0][0] < arr1[0][0] && arr1[0][0] < arr2[1][0] && arr2[1][0] < arr1[1][0]) { // 겹쳐져 있을 때 2
			X = arr1[1][0] - arr2[0][0];
		}
		else if (arr1[0][0] < arr2[1][0] && arr2[1][0] < arr1[1][0]) { // 포함되어 있을 때 1`
			X = arr1[1][0] - arr1[0][0];
		}
		else if (arr2[0][0] < arr1[1][0] && arr1[1][0] < arr2[1][0]) { // 포함되어 있을 때 2
			X = arr2[1][0] - arr2[0][0];
		}
	}

	// Y
	if (Y == 0) {
		if (arr1[1][1] < arr2[0][1] || arr2[1][1] < arr1[0][1]) { // 떨어져있을 때 -> X, Y 중 하나라도 떨어져있으면 두 사각형은 떨어져있음.
			X = (arr1[1][0] - arr1[0][0]) + (arr2[1][0] - arr2[0][0]);
			Y = (arr1[1][1] - arr1[0][1]) + (arr2[1][1] - arr2[0][1]);
		}
		else if (arr1[0][1] < arr2[0][1] && arr2[0][1] < arr1[1][1] && arr1[1][1] < arr2[1][1]) { // 겹쳐져 있을 때 1
			Y = arr2[1][1] - arr1[0][1];
		}
		else if (arr2[0][1] < arr1[0][1] && arr1[0][1] < arr2[1][1] && arr2[1][1] < arr1[1][1]) { // 겹쳐져 있을 때 2
			Y = arr1[1][1] - arr2[0][1];
		}
		else if (arr1[0][1] < arr2[1][1] && arr2[1][1] < arr1[1][1]) { // 포함되어 있을 때 1
			Y = arr1[1][1] - arr1[0][1];
		}
		else if (arr2[0][1] < arr1[1][1] && arr1[1][1] < arr2[1][1]) { // 포함되어 있을 때 2
			Y = arr2[1][1] - arr2[0][1];
		}
	}

	L = 2 * (X + Y);

	return L;
}

int solveS(int arr1[2][2], int arr2[2][2]) {
	int X, Y;

	if (arr1[1][0] < arr2[0][0] || arr2[1][0] < arr1[0][0]) { // 떨어져있을 때
		X = 0;
	}
	else if (arr1[0][0] < arr2[0][0] && arr2[0][0] < arr1[1][0] && arr1[1][0] < arr2[1][0]) { // 겹쳐져 있을 때 1
		X = arr1[1][0] - arr2[0][0];
	}
	else if (arr2[0][0] < arr1[0][0] && arr1[0][0] < arr2[1][0] && arr2[1][0] < arr1[1][0]) { // 겹쳐져 있을 때 2
		X = arr2[1][0] - arr1[0][0];
	}
	else if (arr1[0][0] < arr2[1][0] && arr2[1][0] < arr1[1][0]) { // 포함되어 있을 때 1
		X = arr2[1][0] - arr2[0][0];
	}
	else if (arr2[0][0] < arr1[1][0] && arr1[1][0] < arr2[1][0]) { // 포함되어 있을 때 2
		X = arr1[1][0] - arr1[0][0];
	}

	if (arr1[1][1] < arr2[0][1] || arr2[1][1] < arr1[0][1]) { // 떨어져있을 때
		Y = 0;
	}
	else if (arr1[0][1] < arr2[0][1] && arr2[0][1] < arr1[1][1] && arr1[1][1] < arr2[1][1]) { // 겹쳐져 있을 때 1
		Y = arr1[1][1] - arr2[0][1];
	}
	else if (arr2[0][1] < arr1[0][1] && arr1[0][1] < arr2[1][1] && arr2[1][1] < arr1[1][1]) { // 겹쳐져 있을 때 2
		Y = arr2[1][1] - arr1[0][1];
	}
	else if (arr1[0][1] < arr2[1][1] && arr2[1][1] < arr1[1][1]) { // 포함되어 있을 때 1
		Y = arr2[1][1] - arr2[0][1];
	}
	else if (arr2[0][1] < arr1[1][1] && arr1[1][1] < arr2[1][1]) { // 포함되어 있을 때 2
		Y = arr1[1][1] - arr1[0][1];
	}

	int SA, SB, S;
	SA = (arr1[1][0] - arr1[0][0]) * (arr1[1][1] - arr1[0][1]);
	SB = (arr2[1][0] - arr2[0][0]) * (arr2[1][1] - arr2[0][1]);
	S = SA + SB - (X * Y);

	return S;
}

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int arr1[2][2], arr2[2][2];
		cin >> arr1[0][0] >> arr1[0][1] >> arr1[1][0] >> arr1[1][1];
		cin >> arr2[0][0] >> arr2[0][1] >> arr2[1][0] >> arr2[1][1];

		cout << solveS(arr1, arr2) << " " << solveL(arr1, arr2) << "\n";
	}
}