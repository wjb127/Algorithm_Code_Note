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

long long int arr[68];

long long int koong(int index)
{
	if(index<2)
		arr[index] = 1;
	
	if(index==2)
		arr[index] = 2;
	
	if(index==3)
		arr[index] = 4;
	if(arr[index]!=0)
		return arr[index];

	arr[index] = koong(index-1)+koong(index-2)+koong(index-3)+koong(index-4);

	return arr[index];
}

int main()
{
	memset(arr,0,sizeof(arr));
	int t;
	cin>>t;

	int* num = new int[t];
	f(t)
		cin>>num[i];
	
	f(t)
		p(koong(num[i]));

	delete [] num;
	num = NULL;

	return 0;
}
