#include<iostream>
#include<cstdio>
#include<algorithm>
#include<memory.h>
using namespace std;

int graph[1001][1001];
int DFSV[1001];
int BFSV[1001];
int q[1001];


void DFS(int v,int n)
{
    // 방문확인 후 방문된 정점 출력
    DFSV[v]=1;
    printf("%d ",v);
    
    // 모든 정점 돌기
    for(int i=1;i<=n;i++)
    {
        // 만약 다음 i정점이 아직 방문되지 않았고 이 정점과 지금 정점이 연결되어 있을 경우
        // -> 연결된 쪽으로 방문
        if(graph[v][i] == 1 && DFSV[i] == 0)
            DFS(i,n);
    }
    
    return;
    
    
}

void BFS(int v,int n)
{
    // BFS 구현을 위한 큐의 구성요소
    int front=0,rear=0,pop;
    
    // 큐에 첫 정점 정보 넣고, 방문확인후 방문된 정점 출력
    q[0]=v; 
    rear++;
    BFSV[v]=1;
    printf("%d ",v);
    
    // 큐를 통해서 BFS구현
    while(front<rear)
    {
        // 맨 앞의 정점 빼서 pop에 저장(먼저 검색하기로 선택하기)
        pop=q[front];
        front++;
        
        // 모든 정점을 돌면서 확인하기
        for(int i=1;i<=n;i++)
        {
            // 지금 뺀 정점과 다음 정점이 연결되어있을 때 + 다음 정점이 방문되지 않았을 때
            if(graph[pop][i] == 1 && BFSV[i] == 0)
            {
                // 다음 정점 출력
                printf("%d ",i);
                
                // 큐에 다음 정점 넣기(나중에 검색하도록 준비해놓기)
                q[rear]=i;
                rear++;
                
                // 방문확인
                BFSV[i]=1;
            }
        }
    }
    
    
    return;
    
}

int main()
{
   
    
    // 정점의 수, 간선의 수, 시작 정점 입력
    int N,M,V;
    scanf("%d%d%d",&N,&M,&V);
    
    // 간선간의 연결정보 입력
    int x,y;
    for(int i=0;i<M;i++)
    {
        scanf("%d%d",&x,&y);
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    
    // DFS와 BFS 출력
    DFS(V,N);
    printf("\n");
    BFS(V,N);
        
    
    return 0;
}
