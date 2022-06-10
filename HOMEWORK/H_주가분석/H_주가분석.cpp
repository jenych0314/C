#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> arr)
{
	int result = 0, size;
	size = arr.size();

	for (int i = 1; i < size - 1; i++)
	{
		if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1])
		{
			result++;
		}
	}

	return result;
}

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int n, elem;
		vector<int> arr;
		cin >> n >> elem;

		arr.push_back(elem);
		for (int j = 0; j < n - 1; j++)
		{
			cin >> elem;

			if (arr.back() != elem)
			{
				arr.push_back(elem);
			}
		}

		cout << solve(arr) << "\n";
	}
}