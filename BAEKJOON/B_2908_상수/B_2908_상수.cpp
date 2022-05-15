#include <iostream>
#include <string>

using namespace std;

void solve(int a, int b) {
	string str_a, str_b, re_a, re_b;

	str_a = to_string(a);
	str_b = to_string(b);

	re_a.resize(str_a.size());
	re_b.resize(str_b.size());

	copy(str_a.rbegin(), str_a.rend(), re_a.begin());
	copy(str_b.rbegin(), str_b.rend(), re_b.begin());

	//cout << "re_a: " << re_a << endl;
	//cout << "re_b: " << re_b << endl;

	int rev_a, rev_b;
	rev_a = stoi(re_a);
	rev_b = stoi(re_b);

	//cout << "rev_a: " << rev_a << endl;
	//cout << "rev_b: " << rev_b << endl;

	cout << ((rev_a > rev_b) ? rev_a : rev_b);
}

int main() {
	int a, b;
	cin >> a >> b;

	solve(a, b);
}