#include <iostream>
#include <string>

using namespace std;

bool solve(string name)
{
	int stringLength = name.length();
	if (isdigit(name.front()))
		return false;
	else
	{
		for (char c : name)
		{
			if (!isalnum(c) && c != '_')
				return false;
		}
		return true;
	}
}

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		string name;
		cin >> name;
		cout << solve(name) << endl;
	}
}