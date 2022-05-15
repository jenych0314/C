#include <iostream>

using namespace std;

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int x_distance, y_distance;
	x_distance = (w - x > x) ? x : w - x;
	y_distance = (h - y > y) ? y : h - y;

	cout << ((x_distance > y_distance) ? y_distance : x_distance);
}