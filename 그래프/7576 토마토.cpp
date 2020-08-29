#include<iostream>
#include<algorithm>
#include<memory.h>
#include<queue>
using namespace std;

int n,m,tmp;
int tomato[1001][1001];
int dx[4] = { 0,0,1,-1};
int dy[4] = { 1,-1,0,0};

queue<pair<int,int> > Q;

bool D = true;

int main()
{
    // 입력 받기
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>tmp;
            if(tmp==1)
            {
                // 토마토를 익히고
                tomato[i][j] = 1;
                // 익은 토마토가 있으면 큐에 저장    
                Q.push(make_pair(i,j));
            }
            else
                tomato[i][j] = tmp;
        }
    }
    
    
    
    // 토마토 익는 시뮬레이션
    // 익은 토마토가 사라질 때까지
    // cnt로 날짜세기
    int cnt=1;
    
    while(!Q.empty())
    {
        pair<int,int> now = Q.front();
        Q.pop();
       
        int x = now.first;
        int y = now.second;
        // 4방향 탐색
        for(int i=0;i<4;i++)
        {
        	// 범위가 배열을 넘어가지 않을 때
        	if(x+dx[i]>=1 && x+dx[i]<=n && y+dy[i]>=1 && y+dy[i]<=m)
        	{
            // 0인 곳을 발견하면
                if(tomato[x+dx[i]][y+dy[i]]==0)
                {
                    // 그 곳을 저장하고
                    Q.push(make_pair(x+dx[i],y+dy[i]));
                    // 그 곳의 토마토를 익게 만든다
                    tomato[x+dx[i]][y+dy[i]] = tomato[x][y] + 1;
                    cnt = max(cnt,tomato[x+dx[i]][y+dy[i]]);
                    //cout<<cnt<<endl;
                }
        	}
        }
        //cout<<now.first<<"  "<<now.second<<endl;
        //cnt++;
            
    }
    
    
     // 익지 않은 토마토 있나 확인
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(tomato[i][j]==0)
            {
                D=false;
                break;
            }
            
        }
    }
    
   
    // 다 익었으면 날짜 출력
    if(D)
    {
        cout<<cnt-1<<endl;
    }
    // 아니면 -1 출력
    else
    {
        cout<<-1<<endl;
    }
    
    
    
    
    return 0;
}
