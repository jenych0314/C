#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void solve(int size);
void printArr2D(int **arr, int size);

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;

		solve(n);
	}
}

void solve(int size)
{
	int **arr = new int *[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = new int[size];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = 0;
		}
	}

	int currX = size / 2, currY = 0;
	int nextX = currX + 1, nextY = currY - 1;
	for (int i = 1; i <= size * size; i++)
	{
		arr[currY][currX] = i;
		if (nextX == size)
		{
			nextX = 0;
		}
		if (nextY == -1)
		{
			nextY = size - 1;
		}
		if (arr[nextY][nextX] == 0)
		{
			currX = nextX++;
			currY = nextY--;
		}
		else
		{
			currY++;
			nextX = currX + 1;
			nextY = currY - 1;
		}
		/*cout << i << "\n";
		printArr2D(arr, size);*/
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	for (int i = 0; i < size; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

void printArr2D(int **arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}