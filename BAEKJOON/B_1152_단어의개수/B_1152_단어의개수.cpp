#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> split(string str, char delimiter = ' ') {
	stringstream ss(str);
	string tmp;
	vector<string> v;
	v.clear();

	while (getline(ss, tmp, delimiter)) {
		if (tmp.empty()) continue;
		v.push_back(tmp);
	}

	return v;
}

int main() {
	string str;
	getline(cin, str);
	cout << split(str, ' ').size() << endl;
}