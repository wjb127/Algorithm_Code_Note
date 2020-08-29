#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;

// 입력받은 그대로의 전깃줄
int A[101];
int B[101];

// 정렬된 전깃줄
int a[101];
int b[101];

// dp[i] : i번째까지 가장 긴 증가하는 부분수열
int dp[101];

int main()
{
    memset(dp,0,sizeof(dp));
    
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        cin>>A[i]>>B[i];
    }
    
    for(int i=0;i<n;i++)
    {
        a[i] = A[i];
    }
    
    sort(a,a+n);
    
    for(int i=0;i<n;i++) // A[i]
    {
        for(int j=0;j<n;j++) // a[j]
        {
            if(a[j] == A[i])
            {
                // B를 A의 정렬 순서에 따라 다시 정렬한다.
                b[j] = B[i];
            }
        }
    }
    
    int ans = 0;
    
    // 현재 항 : b[i]
    for(int i=0;i<n;i++)
    {
        // 부분수열의 길이
        int local = 0;
        // 앞의 항 : b[j]
        for(int j=0;j<i;j++)
        {
            // 만약 두 항으로 증가하는 수열을 만들 수 있으면
            if(b[j] < b[i])
            {
                // 부분수열의 길이 갱신
                local = max(dp[j],local);
            }
        }
        // 자신의 길이 1을 더해서 자신의 자리(dp[i])에 저장한다
        dp[i] = local + 1; 
        // 그 중에 가장 큰 것이 정답
        ans = max(dp[i],ans);
    }
    
    cout<<n - ans<<endl;
    
    
    return 0;
}
