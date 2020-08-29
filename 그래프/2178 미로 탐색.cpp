#include<iostream>
#include<cstdio>
#include<algorithm>
#include<memory.h>
using namespace std;

// 좌표와 레벨(거리)를 보유하고 있는 배열
typedef struct levelpoint
{
    int x;
    int y;
    int level;
}LVP;

// BFS구현을 위한 큐 구현
LVP Q[10001];
int front=0,rear=0;

// 기본 인자 세팅
int N,M;

// 미로와 방문 여부
int miro[101][101];
int visit[101][101]={0};

int BFS(int x,int y)
{
    // 큐의 맨 앞 배열의 정보 + 다음 검색 좌표 nx,ny
    int popX,popY,popLV,nx,ny;
    
    // 탐색방향 표현
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    // 큐에 검색 시작 위치의 정보를 넣기
    Q[rear].x=x;
    Q[rear].y=y;
    Q[rear].level=1;
    // 방문을 했다는 표시를 남김
    visit[x][y]=1;
    rear++;
    
    //만약 시작지점이 끝이라면 끝내기
    if(N==1 && M==1)
        return 1;
    
    // 큐에 삽입된 배열들 BFS로 검색
    while(front<rear)
    {
        // 큐의 맨 앞 배열 빼서 검색 시작하기
        popX=Q[front].x;
        popY=Q[front].y;
        popLV = Q[front].level;
        front++;
        
        // 이미 검색대상이 끝의 도착지점일 때
        if(popX==N-1 && popY==M-1)
            return popLV;
        
        // 4개의 방향 검색
        for(int i=0;i<4;i++)
        {
            // 다음 이동할 위치 타게팅
            nx=popX+dx[i];
            ny=popY+dy[i];
            
            // 다음 이동할 위치가 이동가능한 범위 안에 있을 때만
            if(nx>=0 && nx<N && ny>=0 && ny<M)
            {
                // 미로에서 이동가능한 위치이며 아직 방문 안 한 위치일 때
                if(miro[nx][ny]==1 && visit[nx][ny]==0)
                {
                    
                    // 만약 다음 이동위치가 끝의 도착지점이라면
                    if(nx==N-1 && ny==M-1)
                        return popLV+1;
                
                    // 아니라면 큐에 경로길이 1만큼 길게해서 담기(더 검색해야할 배열), 방문한 표시하기
                    Q[rear].x=nx;
                    Q[rear].y=ny;
                    Q[rear].level=popLV+1;
                    visit[nx][ny]=1;
                    rear++;
                }
            }
        }
        
    }
    // 설마 그럴일은 없겠지만 끝으로 못갈때
    return 0;
    
    
}

int main()
{
    // 입력
    scanf("%d %d",&N,&M);
    
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            // 뭐야 ㅅㅂ 이 어이 없는 결과는 ? 
            // 1이 d앞에 붙는 것이 무슨 의미가 있는 것이지?
            scanf("%1d",&miro[i][j]);
    
    //memset(visit,0,sizeof(visit));
    
    // BFS거리
    int ans;
    ans = BFS(0,0);
    
    // 답 출력
    printf("%d\n",ans);
    
    
    return 0;
}
