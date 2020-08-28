#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<memory.h>
#include<string>

#define f(n) for(int i=0;i<n;i++)
#define p(a) cout<<a<<endl
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> P;
	vector<int> M;

	int tmp;
	f(n)
	{

		cin >> tmp;
		if (tmp > 0)
		{
			P.push_back(tmp);
		}
		else
		{
			M.push_back(tmp);
		}
	}

	sort(P.begin(), P.end());
	reverse(P.begin(), P.end());
	sort(M.begin(), M.end());

	int ans = 0;

	for(int i=0;i<P.size();i+=2)
	{
		if ((int)P.size() != 1 && P[i + 1] == 1)
			ans += P[i] + P[i + 1];
		else if((int)P.size() != 1 && P[i + 1] != 1)
			ans += P[i] * P[i + 1];
		else if((int)P.size() == 1)
		{
			ans += P[0];
			break;
		}

		if (i == (int)P.size() - 3)
		{
			ans += P[i + 2];
			break;
		}
		
	}

	
	for (int i = 0; i < M.size(); i += 2)
	{
		if((int)M.size()!=1)
			ans += M[i] * M[i + 1];
		else if((int)M.size() == 1)
		{
			ans += M[0];
			break;
		}

		if (i == (int)M.size() - 3)
		{
			ans += M[i + 2];
			break;
		}
		
	}

	cout << ans << endl;


	return 0;
}
