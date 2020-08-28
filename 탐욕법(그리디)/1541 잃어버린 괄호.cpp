#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<memory.h>
#include<string>

#define p(a) cout<<a<<endl
using namespace std;

int main()
{
	string str;
	cin >> str;
	
	vector<int> a(str.length()+1);
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '+')
		{
			a[i] = -1;
		}
		else if (str[i] == '-')
		{
			a[i] = -2;
		}
		else
		{
			a[i] = str[i] - '0';
		}
		
	}
	a[str.length()] = -3;

	int ans = 0;
	bool minus = false;
	int tmp = 0;
	for (int i = 0; i < a.size(); i++)
	{
		// 마이너스가 아닌 덧셈
		if (a[i] == -1 && !minus)
		{
			ans += tmp;
			tmp = 0;

		}
		// 이미 뺄셈을 만났고 덧셈또는 뺄셈을 다시 만났을 때
		else if (minus && (a[i]==-1 || a[i]==-2))
		{
			ans -= tmp;
			tmp = 0;
		}
		// 첫 뺄셈 만남
		else if(a[i] == -2)
		{
			ans += tmp;
			tmp = 0;
			minus = true;
		}
		
		// 끝부분
		else if (a[i] == -3)
		{
			if (minus)
			{
				ans -= tmp;
				tmp = 0;
			}
			else
			{
				ans += tmp;
				tmp = 0;
			}
			break;
		}
		else 
		{
			tmp = tmp * 10 + a[i];
			//p("a[i] : "<<a[i]);

		}
		
		//p(ans);
	}
	
	cout << ans << endl;




	return 0;
}
