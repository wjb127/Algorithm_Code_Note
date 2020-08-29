#include<cstdio>
#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;

const int INF = 1000000000;
int kebin[101][101];
int sum[101];

int main()
{
    int n,m;
    cin>>n>>m;
    
    
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++) //  범위가 존나 중요하구나 ㅋㅋㅋ
        {
            kebin[i][j] = i==j? 0:INF;
        }
    
    
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        
        if(kebin[a][b]==INF)
        {
            kebin[a][b]=1;
            kebin[b][a]=1;
        }
        
    }
    
    
    for(int k=0;k<=n;k++)
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                {
                    if(kebin[i][k]+kebin[k][j]<kebin[i][j])
                        kebin[i][j] = kebin[i][k]+kebin[k][j];
                    
                }
    
    int MIN=INF,person=0;
    memset(sum,0,sizeof(sum));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            sum[i] += kebin[i][j];
        }
        if(sum[i]<MIN)
        {
            MIN = sum[i];
            person = i;
        }
    }
    cout<<person<<endl;
    
    return 0;
}
