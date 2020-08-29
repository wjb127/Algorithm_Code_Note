#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<memory.h>
#include<string>
#include<cmath>

#define f(n) for(int i=0;i<n;i++)
#define p(a) cout<<a<<endl
#define pb(a) push_back(a)
using namespace std;

int main()
{
	string target;
	string str;

	vector<char> stack;

	// 입력 받기
	cin >> str;
	cin >> target;

	// 스택에 문자열을 하나씩 받아처리 
	for (int i = 0; i < (int)str.length(); i++)
	{
		// 스택에 문자열 넣기
		stack.push_back(str[i]);
		

		// 만약 폭발 문자열 발견시
		if ((int)stack.size() >= target.length())
		{

			bool ans = true;

			// 만약 폭발 문자열 발견시
			for(int j=0;j<(int)target.length();j++)
			{
				if (stack[(int)stack.size()-1-j] != target[(int)target.length()-1-j])
				{
					ans = false;
					break;
				}
			}

			if (ans)
			{

				f((int)target.length())
				{
					//문자열 폭발시키기
					stack.pop_back();
					/*f((int)stack.size())
					{
						cout << stack[i];
					}*/

				}
			}
		}

	}

	if ((int)stack.size() == 0)
		p("FRULA");
	else
		// 출력
		f((int)stack.size())
		{
		cout << stack[i];
		}



	return 0;
}
