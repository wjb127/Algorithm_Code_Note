#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;

long long int arr[501][501];
long long int dp[501][501];

long long int f(int n,int x)
{
    if(dp[n][x]!=0)
        return dp[n][x];
    
    // 기저조건에서 에러가 나기 쉬우므로 조심해야 한다
    // 런타임 에러 : segmentation fault
    // 배열 바깥으로 안나가도록 조심!
    if(n==0)
        return dp[0][0];
    
    if(x==0)
        return dp[n][x] = f(n-1,x) + arr[n][x];
    
    if(x==n)
        return dp[n][x] = f(n-1,x-1) + arr[n][x];
    
    //if(f(n-1,x) > f(n-1,x-1))
    return dp[n][x] = max(f(n-1,x),f(n-1,x-1)) + arr[n][x];
    //else
    //    return dp[n][x] = f(n-1,x-1) + arr[n][x];
}

int main()
{
    int n;
    cin>>n;
    
    memset(arr,0,sizeof(arr));
    memset(dp,0,sizeof(dp));
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i+1;j++)
        {
            cin>>arr[i][j];
        }
    }
    dp[0][0] = arr[0][0];
    
    
    long long int Max=0;
    for(int i=0;i<n;i++)
    {
        //if(f(n,i) > Max)
        Max = max(Max,f(n,i));
    }
    
    cout<<Max<<endl;
    
    return 0;
}
