#include <iostream>
#include <string>

using namespace std;

string solve(string num)
{
	int numLength = num.length();

	if (numLength == 1)
		return "0";

	int *arr = new int[numLength];
	for (int i = 0; i < numLength; i++)
	{ // string(char[]) -> int[]
		arr[i] = num[i] - '0';
	}

	for (int i = numLength - 1; i > 0; i--)
	{
		if (arr[i - 1] >= arr[i])
			arr[i - 1] -= arr[i];
		else
		{
			if ((i - 2) >= 0)
			{ // for index out of range error
				arr[i - 1] -= (arr[i] - 10);
				arr[i - 2]--;
			}
			else
				return "0";
		}
	}

	if (arr[0] == 0)
	{
		string result;
		for (int i = 1; i < numLength; i++)
		{ // int[] -> string(chars)
			result.push_back(char(arr[i] + 48));
		}
		// 11 * 987654321�� 10864197531�� ��� 0987654321�� ��µǴ� ���� Ȯ����
		// 0���� �����ϴ� ���, �� ���� ���ҵ� 0�� ������ ����. 93 -> 96
		if (result.front() == '0')
			return result.substr(1);
		return result;
	}
	else
		return "0";

	delete[] arr;
}

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		string num;
		cin >> num;
		cout << solve(num) << endl;
	}
}