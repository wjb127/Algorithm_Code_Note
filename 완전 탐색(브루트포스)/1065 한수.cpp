#include<iostream>
#include<algorithm>
#include<memory.h>
#include<string>
using namespace std;

int hansu(int i)
{
    if(i==1000)
    {
        return 0;
    }
    else if(i>=100)
    {
        int a=i/100;
        int b=(i%100 - i%10)/10;
        int c=i%10;
        
        if(a-b == b-c)
        {
            return 1;
        }
        else
            return 0;
        
    }
    else
    {
        return 1;
    }
    
    
    
    return 0;
}

int main()
{
    int num;
    cin>>num;
    
    int ans=0;
    
    for(int i=1;i<=num;i++)
    {
        if(hansu(i))
            ans++;
    }
    
    cout<<ans<<endl;
    
    
    return 0;
}
