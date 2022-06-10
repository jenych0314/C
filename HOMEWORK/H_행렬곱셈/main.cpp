#include <iostream>

using namespace std;

void solve(int m, int p, int n);
int **makeMatrix(int m, int n);
void deleteMatrix(int **matrix, int size);
void initMatrix(int **matrix, int m, int n);
int **multiplyMatrix(int **mat1, int **mat2, int m, int p, int n);
void printMatrix(int **matrix, int m, int n);

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		solve(a, b, c);
	}
}

int **makeMatrix(int m, int n)
{
	int **matrix = new int *[m];
	for (int i = 0; i < m; i++)
	{
		matrix[i] = new int[n];
	}

	return matrix;
}

void deleteMatrix(int **matrix, int size)
{
	for (int i = 0; i < size; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

void initMatrix(int **matrix, int m, int n)
{
	int elem;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> elem;
			matrix[i][j] = elem;
		}
	}
}

int **multiplyMatrix(int **mat1, int **mat2, int m, int p, int n)
{
	int **result = makeMatrix(m, n);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			result[i][j] = 0;
			for (int k = 0; k < p; k++)
			{
				result[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}

	return result;
}

void printMatrix(int **matrix, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
}

void solve(int m, int p, int n)
{
	int **mat1 = makeMatrix(m, p);
	int **mat2 = makeMatrix(p, n);

	initMatrix(mat1, m, p);
	initMatrix(mat2, p, n);

	int **mat3 = multiplyMatrix(mat1, mat2, m, p, n);
	printMatrix(mat3, m, n);

	deleteMatrix(mat1, m);
	deleteMatrix(mat2, p);
	deleteMatrix(mat3, m);
}