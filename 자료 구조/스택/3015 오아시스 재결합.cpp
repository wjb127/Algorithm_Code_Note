#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<memory.h>
#include<string>
#include<cmath>

#define f(n) for(int i=0;i<n;i++)
#define p(a) cout<<a<<endl
#define pb push_back

using namespace std;
int n;
int a[500000];
int main() 
{
	// 입력 받기
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
	{
		scanf("%d", &a[i]);
	}

	// 스택 2개 만들기(1개는 개수 세기)
	vector<int> stack;
	vector<int> count;
	// 답
	long long ans = 0;

	// 입력값 검색
	for (int i = 0; i < n; i++) 
	{
		// 동일한 값의 개수
		int cnt = 1;
		// 스택에 내용물이 있을 때
		while (!stack.empty()) 
		{
			// 스택의 마지막보다 입력값이 클 때
			if (stack.back() <= a[i]) 
			{
				// 답에 값의 개수 세기 @@@@@@@@@@@@@@@@@@@@@
				ans += (long long)count.back();
				// 만약 같은 값이 나온다면 @@@@@@@@@@@@@@@@@@@
				if (stack.back() == a[i]) 
				{
					// 개수를 추가 @@@@@@@@@@@@@@@@@@@@
					cnt += count.back();
				}
				// 스택과 카운트 하나씩 제거 @@@@@@@@@@@@@@
				stack.pop_back();
				count.pop_back();
			}
			//만약 스택의 마지막보다 입력값이 작을 때
			else 
			{
				break;
			}
		}

		// 만약 스택이 비어있지 않다면 앞 원소와의 연결도 세기
		if (!stack.empty()) 
		{
			ans += 1;
		}

		// 스택 2개에 값 저장
		stack.pb(a[i]);
		count.pb(cnt);
	}
	printf("%lld\n", ans);
	return 0;
}
