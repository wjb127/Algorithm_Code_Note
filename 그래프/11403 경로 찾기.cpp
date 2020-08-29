#include<iostream>
#include<cstdio>
#include<algorithm>
#include<memory.h>
using namespace std;
const int INF = 100000000;

int g[101][101];

int main()
{
    int n;
    scanf("%d",&n);
    
    // 그래프 초기화
    memset(g,0,sizeof(g));
    
    // 그래프 간선 입력 받기 
    // 0인 경우 : 무한을 대신 넣기
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            scanf("%d",&g[i][j]);
            
            if(g[i][j]==0)
                g[i][j] = INF;
        }
    
    // 플로이드 와샬 알고리즘 적용
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                g[i][j] = min(g[i][j],g[i][k] + g[k][j]);
    
    // 그래프 상태 출력
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
        
            if(g[i][j]==INF)
                printf("%d ",0);
            else
                printf("%d ",1);
        }
        
            printf("\n");
        
     }
        
    
    
    return 0;
}
