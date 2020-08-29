#include<iostream>
using namespace std;
//const int MIN =numeric_limits<int>::min();

int main()
{
	long long x;
	int psum = 0;
	int ret;
	cin >> x;

	int*arr = new int[x];

	for(int i=0;i<x;i++)
	{
		cin >> *(arr+i);
		
		if(i==0){ret = *(arr+i);}

        psum = max(0,psum)+*(arr+i);
		ret = max(ret,psum);
	}


	cout << ret << endl;

	delete arr;



	return 0;
}
