#include <iostream>
using namespace std;

int main() {
	int h, m;
	cin >> h >> m;

	if (m - 45 < 0) {
		m += 15;
		h = (h - 1 < 0) ? h + 23 : h - 1;
	}
	else {
		m -= 45;
	}

	cout << h << " " << m;
}