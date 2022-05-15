#include <iostream>
using namespace std;
// 시침과 분침 사이각 구하기
int angle(int H, int M) {
	float hDegree, mDegree, degree;

	hDegree = H * 30.0 + M * 0.5f;
	mDegree = M * 6.0f;

	degree = (hDegree >= mDegree) ? (hDegree - mDegree) : (mDegree - hDegree);
	return (degree <= 360.0 - degree) ? int(degree) : int(360.0 - degree);
}

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int H, M;
		cin >> H >> M;

		cout << angle(H, M) << endl;
	}

	return 0;
}