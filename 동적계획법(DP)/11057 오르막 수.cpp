#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;

int n;


int cache[1001][11];

int ormac(int N,int full)
{
    //cout<<N<<" "<<full<<endl;
    int ret=0;
    
    if(N==1)
        return cache[N][full] = full;
    
    if(cache[N][full]!=-1)
        return cache[N][full];
    
    for(int i=1;i<=full;i++)
    {
        ret = (ret + ormac(N-1,i))%10007;
    }
    
    
    
    return cache[N][full] = ret;
}

int main()
{
    cin>>n;
    
    memset(cache,-1,sizeof(cache));
    //memset(num,0,sizeof(num));
    
    cout<<ormac(n,10)<<endl;
    
    
    
    return 0;
}
