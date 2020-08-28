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
	int arr[8],sum=0,index[8],bsk[5];

	f(8)
	{
		cin>>arr[i];
		index[i] = arr[i];
	}

	sort(arr,arr+8);


	f(5)
	{
		sum+=arr[i+3];
		for(int j=0;j<8;j++)
		{
			if(arr[i+3] == index[j])
			{
				bsk[i] = j+1;
				break;
			}
		}
	}
		
	p(sum);
	sort(bsk,bsk+5);
	f(5)
		cout<<bsk[i]<<" ";

	return 0;
}
