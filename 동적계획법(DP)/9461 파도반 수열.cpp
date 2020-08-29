#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;

int t;
int n;

long long int cache[101];

long long int p(int x)
{
    //cout<<x<<endl;
    
    if(cache[x]!=0)
        return cache[x];
    
    if(x<=3)
        return cache[x] = 1;
    else if(x==4 || x==5)
        return cache[x] = 2;
    
    cache[x] = p(x-1) + p(x-5);
    
    return cache[x];
    
}

int main()
{
    memset(cache,0,sizeof(cache));
    
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        cout<<p(n)<<"\n";
    }
    
    
    
    
    
    return 0;
}
