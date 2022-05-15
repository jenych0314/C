#include <iostream>
#include <string>

using namespace std;

string solve(string S, int R) {
	string P = "";

	for (char& s : S) {
		P.append(R, s);
	}

	return P;
}
int main() {
	string S, P;
	int T, R;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> R >> S;
		P = solve(S, R);
		cout << P << "\n";
	}
}