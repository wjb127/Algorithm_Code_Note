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



int Doll(int n)
{
	return (n%2+1)%2;
}

int main()
{
	int n;
	cin>>n;


	if(Doll(n)==0)
		p("CY");
	else if(Doll(n)==1)
		p("SK");


	return 0;
}
