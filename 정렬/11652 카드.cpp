#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;

long long int n,tmp,cnt;
long long int card[1000001];


long long int ans=0;
long long int ind=0;

int main()
{
    

    
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>tmp;
        card[i] = tmp;
    }
    if(n==1)
    {
        cout<<card[0]<<endl;
        return 0;
    }
    
    sort(card,card+n);
    
    ans = card[0];
    ind=1;
    cnt=1;
    for(int i=1;i<n;i++)
    {
        if(card[i]==card[i-1])
            cnt++;
        else
            cnt=1;
        
        if(ind < cnt)
        {
            ind = cnt;
            ans = card[i];
        }
 
        
    }
    
    cout<<ans<<"\n";
    
    
    
    
    return 0;
}
