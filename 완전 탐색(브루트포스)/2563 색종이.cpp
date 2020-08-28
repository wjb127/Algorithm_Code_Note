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

class point 
{
private:
	int x;
	int y;
public:
	void setXY(int a,int b)
	{
		x=a;
		y=b;
	}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
};

int main()
{
	int paper[101][101];
	memset(paper,0,sizeof(paper));

	int t;
	cin>>t;

	point* arr = new point[t];

	f(t)
	{
		int a,b;
		cin>>a>>b;
		arr[i].setXY(a,b);
		for(int j=arr[i].getX();j<arr[i].getX()+10;j++)
		{
			for(int k=arr[i].getY();k<arr[i].getY()+10;k++)
			{
				if(paper[j][k]==0)
					paper[j][k]=1;
			}
		}
	}
	int count=0;
	for(int j=0;j<100;j++)
	{
		for(int k=0;k<100;k++)
		{
			if(paper[j][k]==1)
				count++;
		}
	}

	p(count);

	

	delete [] arr;
	arr = NULL;

	return 0;
}
