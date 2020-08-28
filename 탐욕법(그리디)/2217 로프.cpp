#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;

int n,tmp;
int rope[100001];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>rope[i];
    }
    
    sort(rope,rope+n);
    
    int ans=0;
    for(int i=0;i<n;i++)
    {
        rope[i] = rope[i]*(n-i);
        ans = max(rope[i],ans);
    }
    
    cout<<ans<<endl;
    
    
    return 0;
}
