#include <iostream>
using namespace std;

int main() {
	int a, b;
	// ���� �Է� �� ����
	/*do {
		cin >> a >> b;
		cout << a + b << "\n";
	} while (getc(stdin) == ' ');
	*/
	// �� �̻� ���� �����Ͱ� ���� EOF(End Of File)�� �����ϸ� ����
	while (cin >> a >> b) {
		cout << a + b << "\n";
	}
}