#include<iostream>
#include<algorithm>
#include<memory.h>
#include<map>
#include<queue>
using namespace std;

int cnum,link;

int com[101][101];
int visited[101];

queue<int> cache;


int main()
{
    memset(com,0,sizeof(com));
    memset(visited,0,sizeof(visited));
    
    cin>>cnum;
    
    cin>>link;
    
    // 네트워크 설정
    int x,y;
    for(int i=0;i<link;i++)
    {
        cin>>x>>y;
        
        // 왜 이것을 분리하면 틀리는 거지?
        com[x][y] = com[y][x] = 1;
       
    }
    
    
    // 바이러스 전파
    cache.push(1);
    visited[1]=1;
    while(!cache.empty())
    {
        
        
        for(int i=1;i<=100;i++)
        {
            if(com[cache.front()][i] && visited[i]==0)
            {
                
                cache.push(i);
                visited[i]=1;
            }
        }
        cache.pop();
        
    }
    
    int cnt=0;
    for(int i=2;i<=100;i++)
    {
        if(visited[i])
            cnt++;
    }
    
    cout<<cnt<<endl;
    
    return 0;
}
