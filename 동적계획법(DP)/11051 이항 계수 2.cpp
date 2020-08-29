#include<iostream>
#include<cstdio>
#include<algorithm>
#include<memory.h>
using namespace std;

int n,k;

int cache[1001][1001];

int C(int n,int k)
{
    if(cache[n][k]!=0)
        return cache[n][k];
    
    if(n==k || k==0)
    {
        return cache[n][k] = 1;
    }
    
    return cache[n][k] = (C(n-1,k)+C(n-1,k-1))%10007;
    
    
  
}
int main()
{
    memset(cache,0,sizeof(cache));
    
    scanf("%d%d",&n,&k);
    
    printf("%d\n",C(n,k));
    
    return 0;
}
