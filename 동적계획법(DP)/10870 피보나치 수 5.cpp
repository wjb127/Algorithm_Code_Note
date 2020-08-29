#include<iostream>
#include<cstdio>
#include<memory.h>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;

#define f(n) for(int i=0;i<n;i++)
#define p(a) cout<<a<<endl

long Fibo[1000];

long F(long n)
{
	if(n==0 || n==1)
		Fibo[n] = n;
	else 
		Fibo[n] = F(n-1) + F(n-2);

	return Fibo[n];
}

int main()
{
	int n;
	cin>>n;

	memset(Fibo, 0,sizeof(Fibo));

	p(F(n));

	return 0;
}
