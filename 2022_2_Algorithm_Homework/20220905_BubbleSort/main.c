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

/* BubbleSort 함수 */
void bubbleSort(int arr[], int n)
{
	int countCmpOps = 0; // 비교 연산자 실행 횟수
	int countSwaps = 0; // swap 함수 실행 횟수

	// bubble sort 알고리즘 구현
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

/* BubbleSort 함수 - Improved Version 1 */
void bubbleSortImproved1(int arr[], int n)
{
	int countCmpOps = 0; // 비교 연산자 실행 횟수
	int countSwaps = 0; // swap 함수 실행 횟수
	bool swapped;

	// bubble sort의 개선된 알고리즘 (1) 구현
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

/* BubbleSort 함수 - Improved Version 2 */
void bubbleSortImproved2(int a[], int n)
{
	int countCmpOps = 0; // 비교 연산자 실행 횟수
	int countSwaps = 0; // swap 함수 실행 횟수
	int last;
	// bubble sort의 개선된 알고리즘 (2) 구현


	printf("%d %d ", countCmpOps, countSwaps);
}

void copyArray(int a[], int b[], int n)
{
	for (int i = 0; i < n; i++)
		a[i] = b[i];
}