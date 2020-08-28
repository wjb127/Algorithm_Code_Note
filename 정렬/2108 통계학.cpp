#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<memory.h>
#include<string>
#include<cmath>

#define f(n) for(int i=0;i<n;i++)
#define p(a) cout<<a<<endl
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> v(n);

	int arr[8001];
	memset(arr, 0, sizeof(arr));

	vector<int> pro;

	int sum = 0;
	int most = 0;
	int cbg = 0;
	f(n)
	{
		cin >> v[i];
		sum += v[i];
		
		if (v[i] >= 0)
		{
			arr[v[i]]++;
		

			if (arr[v[i]] > most)
			{

				most = arr[v[i]];
				cbg = v[i];
			}
			
		}
		else
		{
			arr[8001 + v[i]]++;
			if (arr[8001 + v[i]] > most)
			{

				most = arr[8001 + v[i]];
				cbg = v[i];
			}
			
			
		}
			
	}
	sort(v.begin(), v.end());
	
	
	
	f(8001)
	{
		if (arr[i] == most)
		{
			//p(most << "M");
			if (i > 4000)
				pro.push_back(i - 8001);
			else
			{
				pro.push_back(i);
			}
		}
		
			

	}
	sort(pro.begin(), pro.end());

	//p(pro.size()<<" "<<most);

	p(floor(((double)sum / (double)n)+0.5));
	p(v[(int)v.size() / 2]);

	if (pro.size() >= 2)
		p(pro[1]);
	else
		p(cbg);
	p(v[(int)v.size() - 1] - v[0]);




	return 0;
}
