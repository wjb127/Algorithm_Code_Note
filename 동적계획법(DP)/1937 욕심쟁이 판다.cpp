#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;

// 정사각형 숲의 한 변의 길이
int n;

// 숲과 탐색결과 기록하는 지도
int forest[501][501];
int dpmap[501][501];

// 탐색방향
int vectx[4]={1,0,-1,0};
int vecty[4]={0,1,0,-1};

// 전체적 최대 생존기간
int entire = 0;

// (x,y) 좌표 탐색
void dfs(int x,int y)
{
    // 다음 탐색할 좌표(x,y)근처
    int nextX;
    int nextY;
    
    // 부분적 최대 생존기간
    
    int local = 0;
    
    for(int i=0;i<4;i++)
    {
        // x,y,의 상하좌우 방향으로 탐색
        nextX = x + vectx[i];
        nextY = y + vecty[i];
        
        // 만약 숲의 범위를 넘어가면 탐색하지 않고 넘기기
        if(nextX<0 || nextX>=n || nextY<0 || nextY>=n)
            continue;
        
        // 대나무가 더 많은 땅이 있을 때
        if(forest[x][y] < forest[nextX][nextY])
        {
            // 탐색기록이 없다면
            if(dpmap[nextX][nextY] == 0)
                // 이곳도 탐색해서 기록한다
                dfs(nextX,nextY);
            
            // 그리고 대나무를 다 먹었거나(다 먹은 부분에서 local = 0) 
            // 숲의 범위를 넘어가거나 하면 재귀가 종료되는데,
            // 이 때 부분적 최대 생존기간을 저장한다
            local = max(dpmap[nextX][nextY],local);
        }
 
       
    }
    // 현재 탐색기록 : 부분적 최대에서 1 더하기
    dpmap[x][y] = local + 1;
    
    // 전체적 최대 : 탐색기록 중 최대
    entire = max(dpmap[x][y],entire);
    
}

int main()
{
    memset(forest,0,sizeof(forest));
    memset(dpmap,0,sizeof(dpmap));
    
    //int n;
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>forest[i][j];
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dpmap[i][j]==0)
                dfs(i,j);
            // 아래의 코드가 필요없는 이유 : 0인 곳만 찾아서 탐색하면
            // 중복되지 않게 탐색됨
            //memset(dpmap,0,sizeof(dpmap));
            
        }
    }
    
    cout<<entire<<endl;
    
    
    
    
    return 0;
}
