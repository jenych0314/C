#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = n; i >= 1; i--) {
		//cout << i << endl; //시간초과남.
		cout << i << "\n";
	}
}