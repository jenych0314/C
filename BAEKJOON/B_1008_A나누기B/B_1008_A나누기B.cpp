#include <iostream>
using namespace std;

int main() {
	double a, b;
	cin >> a >> b;

	//precision(n) -> ��� �� �Ǽ� ��ü �ڸ� ���� n�ڸ��� ǥ��
	cout.precision(12);
	//fixed -> ���� �Ҽ��� ǥ��, fixed �������� ������ ��µ���
	// �Ҽ��� �Ʒ��� ������ precision���� �Ѱ��� �� ��ŭ ��� ��.
	// ����, fixed�� �����ϰ� ���� ���� cout.unsetf(ios::fixed)
	cout << fixed;
	cout << a / b;

	return 0;
}