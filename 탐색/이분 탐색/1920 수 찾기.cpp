#include <cstdio>
using namespace std;

void QuickSort(int arr[], int left, int right)
{
	int i = left, j = right;
	int pivot = arr[(left + right) / 2];
	int temp;

	do {
		while (arr[i] < pivot) i++;
		while (arr[j] > pivot) j--;

		if (i <= j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);

	if (left < j) QuickSort(arr, left, j);
	if (right > i) QuickSort(arr, i, right);
}


int BinarySearch(int arr[], int find, int low, int high)
{
	if (low > high) return 0;

	int mid = (low + high) / 2;

	if (arr[mid] > find) 
		return BinarySearch(arr, find, low, mid - 1);
	else if (arr[mid] < find) 
		return BinarySearch(arr, find, mid + 1, high);
	else
		return 1;

}


int main()
{
	int N, M;
	int A[100000] = { 0 };
	int num[100000] = { 0 };
	int i;

	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);
	scanf("%d", &M);
	for (i = 0; i < M; i++)
		scanf("%d", &num[i]);

	QuickSort(A, 0, N - 1);

	for (i = 0; i < M; i++)
		printf("%d\n", BinarySearch(A, num[i], 0, N - 1));


	return 0;
}
