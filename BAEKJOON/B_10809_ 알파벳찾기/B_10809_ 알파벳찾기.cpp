#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string S;
	vector<int> v(26, -1);

	cin >> S;

	for (int i = 0; i < S.length(); i++) {
		//cout << S[i] << endl;
		int idx = S[i] - 'a';
		if (v[idx] == -1) v[idx] = i;
	}

	for (int& elem : v) {
		cout << elem << " ";
	}
}