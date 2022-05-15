#include <iostream>
using namespace std;

int main() {
	double a, b;
	cin >> a >> b;

	//precision(n) -> 출력 할 실수 전체 자리 수를 n자리로 표현
	cout.precision(12);
	//fixed -> 고정 소수점 표기, fixed 다음부터 들어오는 출력들은
	// 소수점 아래로 설정한 precision으로 넘겨준 값 만큼 출력 됨.
	// 만약, fixed를 해제하고 싶을 때는 cout.unsetf(ios::fixed)
	cout << fixed;
	cout << a / b;

	return 0;
}