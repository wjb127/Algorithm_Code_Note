#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<memory.h>
#include<algorithm>
using namespace std;

// 테스트케이스
int  tc;
// 순열의 크기
int N;
// 순열 저장
int seq[1001];
// 순열 중에 사이클에 들어간 수를 표시
int cache[1001];
// 순열사이클의 수
int num;

// dfs
void dfs(int x)
{
    // 이미 사이클 안에 있을 경우(사이클 시작점)
    if(cache[x]==1)
        return;
    // 사이클에 미포함시
    else
    {
        cache[x]=1;
        dfs(seq[x]);
    }
    
}

// 순열사이클의 수 세기
int seqCycle()
{
    num=0;
    
    
    // 한 개의 사이클 찾기
    // cache 검색으로 아직 사이클에 안 들어간 순열의 수 찾기
    // index:인덱스, seq[index]:순열값
    int index;
    for(index=1;index<=N;index++)
    {
        if(cache[index]==0)
        {
            
            dfs(index);
            num++;
        }
        
    }
        
    
    return num;
}


int main()
{
    
    scanf("%d",&tc);
    
    for(int i=0;i<tc;i++)
    {
        scanf("%d",&N);
        for(int j=1;j<=N;j++)
        {
            scanf("%d",&seq[j]);
            cache[j]=0;
        }
        
        printf("%d\n",seqCycle());

    }
   
    
    return 0;
}
