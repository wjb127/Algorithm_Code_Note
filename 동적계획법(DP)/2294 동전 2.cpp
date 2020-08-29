#include<iostream>
#include<memory.h>
#include<algorithm>
using namespace std;

int n,k;



int coin[101];
long long int cache[10001];

// K를 채우는 방법의 수를 반환한다.
long long int minNum(int K)
{
    
    long long int ret=987654321;
    // 채우지 못하는 경우 : 기저 조건
    if(K<0)
        return 0;
    if(K==0)
        return 0;
    
    
    
    // K에 대해서 항상 같은 경우의 수가 나오므로
    if(cache[K]!=-1)
        return cache[K];
    
    for(int i=0;i<n;i++)
    {
        if(K - coin[i]>=0) 
	        ret = min(ret,1 + minNum( K - coin[i] ));
    }
   
    
    
    return cache[K] = ret;
}

int main()
{
    cin>>n>>k;
    
    
    for(int i=0;i<n;i++)
    {
        cin>>coin[i];
    }
    
    for(int i=0;i<=k;i++)
    {
        cache[i] = -1;
    }
    
    long long int ans = minNum(k);
    if(ans==0 || ans==987654321)
        cout<<-1<<endl;
    else
        cout<<ans<<endl;;
    

    
    return 0;
}
