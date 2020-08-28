#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace::std;
 
int Wine[10001];
int dp[10001];


 
int main(void)
{
    int N;
    cin >> N;
    
    memset(Wine,0,sizeof(Wine));
    memset(dp,0,sizeof(dp));
    
    for (int i = 1; i <= N; i++)
        cin >> Wine[i];
    dp[1] = Wine[1];
    dp[2] = Wine[1] + Wine[2];
    for (int i = 3; i <= N; i++)
    {
        // 더하지 않는 것이 최대인 케이스
        int num1 = dp[i - 1];
        // 연속으로 더하는 것이 최대인 케이스
        int num2 = dp[i - 3] + Wine[i - 1] + Wine[i];
        // 불연속으로 더하는 것이 최대인 케이스
        int num3 = dp[i - 2] + Wine[i];
        // 항상 끝부분의 최대를 유지시킨다
        dp[i] = max(max(num1, num2), num3);
    }
    cout << dp[N] << endl;
}
