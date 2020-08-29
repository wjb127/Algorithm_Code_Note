#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;

int N,L,R;

long long int cache[101][101][101];



int main()
{
    memset(cache,0,sizeof(cache));
    cache[1][1][1] = 1;
    cache[2][1][2] = 1;
    cache[2][2][1] = 1;
    cin>>N>>L>>R;
    for(int i=2;i<=N;i++)
        for(int j=1;j<=L;j++)
            for(int k=1;k<=R;k++){
            	//cout<<i<<j<<k<<endl;
            
    cache[i][j][k] = (cache[i-1][j-1][k] + cache[i-1][j][k-1] + cache[i-1][j][k]*(i-2))%1000000007;
            }
    cout<<cache[N][L][R]<<endl;
    
    
    
    
    
    return 0;
}
