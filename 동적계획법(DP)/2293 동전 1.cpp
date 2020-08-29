#include<cstdio>
#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;

int coin[102];
int sum[10002];


int main()
{
    // 동전 종류의 개수와 합계 입력
    int n,k;
    scanf("%d %d",&n,&k);
    
    // 초기화
    //memset(coin,0,sizeof(coin));
    //memset(sum,0,sizeof(sum));
    sum[0] = 1; // 합계가 0인 경우는 모든 코인을 안 쓰는 경우의 수 1가지
    
    // 동전 종류 입력 + 합계 초기화
    for(int i=0;i<n;i++)
    {
        scanf("%d",&coin[i]);
        
    }
    
    // 현재 코인 : coin[i]로 설정한 뒤
    for(int i=0;i<n;i++)
    {
        // 합계별 경우의 수 넣기(각 수 한 개의 경우) // 틀렸음 -> 왜 틀렸지? 이해가 안되네;;
        //sum[coin[i]]++;
        
        // 뒤의 합계별 경우의 수 계산 : 기존의 합계 + 이전 코인으로 만들어지는 합계의 경우의 수
        for(int j=coin[i];j<=k;j++) // 위의 코드가 맞다면 coin[i]+1로 시작
        {
            if(j-coin[i]>=0)
                sum[j] = sum[j] + sum[j - coin[i]];
        }
    }
    
    printf("%d\n",sum[k]);
    
    
    
    return 0;
}
