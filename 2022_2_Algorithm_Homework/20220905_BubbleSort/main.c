#include <stdio.h>
#include <stdbool.h>

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

void bubbleSort(int arr[], int n)
{
	int countCmpOps = 0;
	int countSwaps = 0;

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

void bubbleSortImproved1(int arr[], int n)
{
	int countCmpOps = 0;
	int countSwaps = 0;
	bool swapped;

	for (int i = 1; i < n; i++) {
		swapped = false;

		for (int j = 1; j <= n - i; j++) {
			countCmpOps++;

			if (arr[j - 1] > arr[j]) {
				swap(arr[j - 1], arr[j]);
				swapped = true;

				countSwaps++;
			}
		}

		if (swapped == false)
			break;
	}

	printf("%d %d ", countCmpOps, countSwaps);
}

void bubbleSortImproved2(int arr[], int n)
{
	int countCmpOps = 0;
	int countSwaps = 0;
	int lastSwappedPos = n, swappedPos;

	while (lastSwappedPos > 0) {
		swappedPos = 0;

		for (int i = 1; i < lastSwappedPos; i++) {
			countCmpOps++;

			if (arr[i - 1] > arr[i]) {
				swao(arr[i - 1], arr[i]);
				swappedPos = i;

				countSwaps++;
			}
		}

		lastSwappedPos = swappedPos;
	}

	printf("%d %d ", countCmpOps, countSwaps);
}

void copyArray(int arr1[], int arr2[], int n)
{
	for (int i = 0; i < n; i++)
		arr1[i] = arr2[i];
}