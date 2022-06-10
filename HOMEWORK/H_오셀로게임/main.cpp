#include <iostream>

using namespace std;

void solve(int cnt);

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

void solve(int cnt)
{
	// �������� �ʱ�ȭ
	char **arr = new char *[8];
	for (int i = 0; i < 8; i++)
	{
		arr[i] = new char[8]{'+', '+', '+', '+', '+', '+', '+', '+'};
	}
	arr[3][3] = arr[4][4] = 'O';
	arr[3][4] = arr[4][3] = 'X';

	for (int i = 0; i < cnt; i++)
	{
		int xIdx, yIdx;
		cin >> xIdx >> yIdx;
		// �迭�� ��ǥ���� ����.
		xIdx--;
		yIdx--;

		char piece = (i % 2 == 0) ? 'X' : 'O';
		arr[yIdx][xIdx] = piece;
		int direction[8][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}}; // ������ ������ �������� ��� �ִ� �迭 (x, y)
		for (int i = 0; i < 8; i++)
		{
			int path[8][2] = {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}}; // ���� piece�� �ٸ� piece�� �߰��� ��� ������ ��θ� ����� �迭 (x, y)
			int currX = xIdx + direction[i][0], currY = yIdx + direction[i][1];								   // ���� �������� �ִ� ����� ��ǥ
			bool check = false;																				   // ���� piecd�� �������� ���� �Ǵ�
			int pathCnt = 0;																				   // path�� �� ����
			while ((0 <= currX && currX <= 7) && (0 <= currY && currY <= 7))
			{								  // ���� ��ǥ�� ������ �� ������ ���� ��
				if (arr[currY][currX] == '+') // �� ĭ�� ���
					break;
				else if (arr[currY][currX] == piece)
				{ // ���� piece�� ���� piece�� ���
					check = true;
					break;
				}
				else
				{ // ���� piece�� �ٸ� piece�� ���
					// path�� (currX, currY) �߰�
					path[pathCnt][0] = currX;
					path[pathCnt][1] = currY;
					pathCnt++;

					// ���� ���� �������� currX, currY ����
					currX += direction[i][0];
					currY += direction[i][1];
				}
			}
			if (check)
			{ // ���� piece�� ���� piece�� ������ ��
				for (int i = 0; i < 8; i++)
				{
					if (path[i][0] == -1 || path[i][1] == -1) // ������ ��ΰ� �ƴ� ��� ����
						break;
					arr[path[i][1]][path[i][0]] = piece; // ������ ����� ��� ���� piece ������� ����.
				}
			}
		}
	}

	// ���� ��, �� �� ���� ����
	int white = 0, black = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] == 'O')
				white++;
			if (arr[i][j] == 'X')
				black++;
		}
	}

	// ��� ���
	cout << black << " " << white << "\n";
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << arr[j][i];
		}
		cout << "\n";
	}

	for (int i = 0; i < 8; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}