#include <cstdio>

int main()
{
    
    // N입력 받기
    int N;
    int dp[100001] = {};
    scanf("%d", &N);
    
    // 현재 제곱합의 경우의 수 : dp[i]
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j*j <= i; j++)
        {
            if (dp[i] > dp[i - j*j] + 1 || dp[i] == 0)
                dp[i] = dp[i - j*j] + 1;
        }
    }
    
    // 정답 출력
    printf("%d\n", dp[N]);
 
    return 0;
}
