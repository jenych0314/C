#include <iostream>

using namespace std;

int main() {
	int prev, now;
	bool p_b, n_b, ordered = true;

	cin >> prev >> now;
	n_b = (prev > now) ? true : false;

	for (int i = 0; i < 6; i++) {
		prev = now;
		cin >> now;

		p_b = n_b;
		n_b = (prev > now) ? true : false;

		if (n_b != p_b) {
			cout << "mixed";
			ordered = false;
			break;
		}
	}

	if (ordered) cout << ((n_b) ? "descending" : "ascending");
}