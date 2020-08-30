#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;

int n,m;
int MAP[501][501];
int dp[501][501];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int cheat=0;

int dfs(int x,int y)
{
    int ret=1;
    //cout<<x<<y<<" "<<MAP[x][y]<<endl;
    if(dp[x][y]!=-1)
        return dp[x][y];
    else
        dp[x][y]=0;
    if(x==1 && y==1)
    {
    	
    	return dp[1][1] = 1;
    }
    
    
    
        
    
    for(int i=0;i<4;i++)
    {
        if((1 <= x+dx[i]) && (x+dx[i] <= n))
        {
            if((1 <= y+dy[i]) && (y+dy[i] <= m))
            {
                if(MAP[x][y] < MAP[x+dx[i]][y+dy[i]])
                {
                    //dp[x+dx[i]][y+dy[i]] = dp[x][y]
                    //cout<<x<<y<<" "<<dfs(x+dx[i],y+dy[i])<<endl;
                    dp[x][y] += dfs(x+dx[i],y+dy[i]);
                    
                }
            }
        }
        
    }
    
    //cout<<x<<" "<<y<<endl;
    
    return dp[x][y];
}

int main()
{
    memset(MAP,0,sizeof(MAP));
    memset(dp,-1,sizeof(dp));
    
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>MAP[i][j];
        }
    }
    
    dp[1][1] = 1;
    cout<<dfs(n,m)<<endl;
    
    //cout<<cheat<<endl;
    
    
    
    return 0;
}
