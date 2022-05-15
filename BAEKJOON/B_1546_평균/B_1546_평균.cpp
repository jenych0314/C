#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, max = 0;
	cin >> N;
	vector<double> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
		if (v[i] > max) max = v[i];
	}

	double average = 0;
	for (int i = 0; i < N; i++) {
		v[i] = v[i] / max * 100;
		average += v[i];
	}

	average /= N;

	cout.precision(12);
	cout << fixed;
	cout << average;
}