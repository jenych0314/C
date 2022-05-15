#include <iostream>
using namespace std;

int main() {
	int a, b;
	// 엔터 입력 시 종료
	/*do {
		cin >> a >> b;
		cout << a + b << "\n";
	} while (getc(stdin) == ' ');
	*/
	// 더 이상 읽을 데이터가 없어 EOF(End Of File)을 리턴하면 종료
	while (cin >> a >> b) {
		cout << a + b << "\n";
	}
}