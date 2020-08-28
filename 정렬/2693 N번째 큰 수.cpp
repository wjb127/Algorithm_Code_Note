#include<iostream>
#include<cstdio>
#include<memory.h>
#include<algorithm>
#include<string>
#include<cmath>
#include<string>
using namespace std;

#define f(n) for(int i=0;i<n;i++)
#define p(a) cout<<a<<endl

int main()
{
	int t;
	cin>>t;

	f(t)
	{
		int arr[10];
		for(int j=0;j<10;j++)
		{
			cin>>arr[j];
		}
		sort(arr,arr+10);
		p(arr[7]);
	}

	
	return 0;
}
