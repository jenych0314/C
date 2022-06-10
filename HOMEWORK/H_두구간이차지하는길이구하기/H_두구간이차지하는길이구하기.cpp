#include <iostream>
#include <vector>

using namespace std;

// ���ϰų� �� ��ħ.
// a < b <= c < d
// c < d <= a < b

// ��ħ
// a <= c, c <= b, b <= d
// c <= a, a <= d, d <= b

// �� �ʿ� ���Ե�.
// a <= c < d <= b
// c <= a < b <= d

int *solve(int a, int b, int c, int d)
{
	int *result = new int[2];

	if ((b <= c && b < d) || (d <= a && d < b))
	{
		result[0] = 0;
		result[1] = (d - c) + (b - a);
	}
	else if (a <= c && c <= b && b <= d)
	{
		result[0] = b - c;
		result[1] = (d - a);
	}
	else if (c <= a && a <= d && d <= b)
	{
		result[0] = d - a;
		result[1] = (b - c);
	}
	else if (a <= c && d <= b)
	{
		result[0] = d - c;
		result[1] = b - a;
	}
	else if (c <= a && b <= d)
	{
		result[0] = b - a;
		result[1] = d - c;
	}

	return result;
}

int main()
{
	int T, a, b, c, d;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> a >> b >> c >> d;
		int *p = solve(a, b, c, d);
		cout << p[0] << " " << p[1] << "\n";
	}
}
