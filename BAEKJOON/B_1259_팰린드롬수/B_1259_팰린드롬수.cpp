#include <iostream>
#include <string>

using namespace std;

int main() {
	string num, rev_num;

	while (true) {
		cin >> num;
		if (num == "0") break;

		rev_num.resize(num.size());
		copy(num.rbegin(), num.rend(), rev_num.begin());

		cout << ((num == rev_num) ? "yes" : "no") << "\n";
	}
}