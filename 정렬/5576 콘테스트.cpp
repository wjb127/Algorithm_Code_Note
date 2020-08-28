#include<iostream>
#include<memory.h>
#include<algorithm>
using namespace std;

#define f(n) for(int i=0;i<n;i++)
#define p(a) cout<<a<<endl

void sort(int arr[], int size)
{
	for(int i=0;i<size;i++)
	{
		int tmp = arr[i];
		for(int j=i;j<size;j++)
		{
			
			if(arr[j]>tmp)
			{
				tmp=arr[j];
				arr[j]=arr[i];
				arr[i]=tmp;
			}
		}

	}

}

int main()
{
	int w[10];
	int k[10];
	int sumw=0,sumk=0;
	f(10)
	{
		cin>>w[i];
	}
	f(10)
	{
		cin>>k[i];
		
	}
	sort(w,10);
	sort(k,10);
	sumw = w[0] + w[1] + w[2];
	sumk = k[0] + k[1] + k[2];

	cout<<sumw<<" "<<sumk<<endl;

	return 0;
}
