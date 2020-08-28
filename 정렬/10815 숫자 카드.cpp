#include<iostream>
#include<cstdio>
#include<algorithm>
#include<memory.h>
using namespace std;
int n, m;
int arrn[500001], arrm[500001], arr[500001];

int BS(int arr[], int find, int left, int right)
{
	

	if (left > right)
		return 0;

	int mid = (left + right) / 2;

	if (arr[mid] == find)
	{
		return 1;
	}
	else if (arr[mid] > find)
	{
		return BS(arr, find, left, mid-1);
	}
	else if (arr[mid] < find)
	{
		return BS(arr, find, mid + 1, right);
	}
	

	
}

int main()
{
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf("%d", &arrn[i]);
	}
	scanf("%d", &m);
	for(int i=0;i<m;i++)
	{
		scanf("%d", &arrm[i]);

	}
	sort(arrn, arrn + n);

	for (int i = 0; i < m; i++)
	{
		arr[i] = BS(arrn, arrm[i], 0, n);
	}

	
	for (int i = 0; i < m; i++)
	{
		printf("%d ", arr[i]);
	}


	return 0;
}
