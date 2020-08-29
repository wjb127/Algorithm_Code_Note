#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;

int N;

int p[1001];

int cache[1001];

int maxSales(int cases)
{
    //cout<<cases<<endl;
    int ret=0;
    
    if(cases==0)
        return 0;
        
    if(cases==1)
        return p[0];
    
    if(cache[cases]!=-1)
        return cache[cases];
    
    for(int i=1;i<=cases;i++)
    {
        // p[i-1] : i개 묶음의 가격
        // cases : 남은 붕어빵의 개수
        // maxSales : cases개의 붕어빵을 가지고 만들수 있는 최고 매출
        
        ret = max(ret,p[i-1]+maxSales(cases - i));
    }
    
    
    return cache[cases] = ret;
}

int main()
{
    cin>>N;
    
    memset(cache,-1,sizeof(cache));
    
    for(int i=0;i<N;i++)
    {
        cin>>p[i];
    }
    
    cout<<maxSales(N)<<endl;
    
    
    return 0;
}
