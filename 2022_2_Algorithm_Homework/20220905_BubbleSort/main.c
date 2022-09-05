#include <stdio.h>

#define MAX_SIZE 1000

void bubbleSort(int arr[], int n);
void bubbleSortImproved1(int arr[], int n);
void bubbleSortImproved2(int arr[], int n);
void copyArray(int arr1[], int arr2[], int n);

int main() {
	int numTestCases;
	int arr1[MAX_SIZE], arr2[MAX_SIZE];

	scanf("%d", &numTestCases);

	for (int i = 0; i < numTestCases; i++) {
		int num;
		scanf("%d", &num);

		for (int j = 0; j < num; j++) {
			scanf("%d", &arr2[j]);
		}

		copyArray(arr1, arr2, num);
		bubbleSort(arr1, num);

		copyArray(arr1, arr2, num);
		bubbleSortImproved1(arr1, num);

		copyArray(arr1, arr2, num);
		bubbleSortImproved2(arr1, num);

		printf("\n");
	}
	
	return 0;
}

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/* BubbleSort �Լ� */
void bubbleSort(int arr[], int n)
{
	int countCmpOps = 0; // �� ������ ���� Ƚ��
	int countSwaps = 0; // swap �Լ� ���� Ƚ��

	// bubble sort �˰��� ����
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= n - i; j++) {
			countCmpOps++;
			if (arr[j - 1] > arr[j]) {
				swap(arr[j - 1], arr[j]);
				countSwaps++;
			}
		}
	}

	printf("%d %d ", countCmpOps, countSwaps);
}

/* BubbleSort �Լ� - Improved Version 1 */
void bubbleSortImproved1(int arr[], int n)
{
	int countCmpOps = 0; // �� ������ ���� Ƚ��
	int countSwaps = 0; // swap �Լ� ���� Ƚ��
	bool swapped;

	// bubble sort�� ������ �˰��� (1) ����
	for (int i = 1; i < n; i++) {
		swapped = false;

		for (int j = 1; j <= n - i; j++) {
			if (arr[j - 1] > arr[j]) {
				swap(arr[j - 1], arr[j]);
				swapped = true;
			}
		}

		if (swapped == false)
			break;
	}
	printf("%d %d ", countCmpOps, countSwaps);
}

/* BubbleSort �Լ� - Improved Version 2 */
void bubbleSortImproved2(int a[], int n)
{
	int countCmpOps = 0; // �� ������ ���� Ƚ��
	int countSwaps = 0; // swap �Լ� ���� Ƚ��
	int last;
	// bubble sort�� ������ �˰��� (2) ����


	printf("%d %d ", countCmpOps, countSwaps);
}

void copyArray(int a[], int b[], int n)
{
	for (int i = 0; i < n; i++)
		a[i] = b[i];
}