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


long long int arr[1000000];


long long int toOne(long long int index)
{
	if(index==0) // 없는 셈 치는 인덱스
	{
		arr[0] = 0;
		return 0;
	}

	if(index==1)
	{
		arr[1] = 0;
		return 0;
	}

	if(arr[index]!=0)
	{
		return arr[index];
	}

	
	if(index%3!=0)
	{
		if(index%2!=0)
		{
			//p(11111);
			arr[index] = toOne(index-1)+1;
		}
		else if(index%2==0)
		{
			//p(22222);
			arr[index]=min(toOne(index-1)+1,toOne(index/2)+1);
		}
	}

	else if(index%3==0)
	{
		if(index%2!=0)
		{
			//p(33333);
			arr[index]=min(toOne(index-1)+1,toOne(index/3)+1);
		}
		else if(index%2==0)
		{
			//p(44444);
			arr[index]=min(toOne(index-1)+1,min(toOne(index/2)+1,toOne(index/3)+1));
		}
	}

	
	//p(index);
	return arr[index];

}

int main()
{
	memset(arr,0,sizeof(arr));
	int index;

	cin>>index;

	p(toOne(index));

	return 0;
}
