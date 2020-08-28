#include<iostream>
#include<memory.h>
#include<algorithm>
using namespace std;

#define f(n) for(int i=0;i<n;i++)
#define p(a) cout<<a<<endl

int main()
{
	int n;
	int arr[1001];

	cin>>n;
	f(n)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	f(n)
	{
		p(arr[i]);
	}

	return 0;
}
