#include <iostream>

using namespace std;

int solve(int year, int month, int day) {
	int const YEAR = 1582;
	int const MONTH[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int total = 0;
	total += (year - 1) * 365 + ((year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400);

	for (int i = 0; i < month - 1; i++) {
		total += MONTH[i];
	}
	if ((month >= 3) && (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))) total++;

	total += day;
	return total % 7;
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int year, month, day;
		cin >> year >> month >> day;
		cout << solve(year, month, day) << endl;
	}
}