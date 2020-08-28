#include<iostream>
#include<memory.h>
#include<algorithm>
using namespace std;

long long int n,k;



long long int coin[101];




int main()
{
    // 입력
    cin>>n>>k;
    
    
    int count=0;
    
    for(int i=0;i<n;i++)
    {
        cin>>coin[i];
    }
    
    // 문제풀이
    int i=0;
    while(i<n)
    {
        if(k>=coin[n-i-1])
        {
            k -= coin[n-i-1];
          
            count++;
        }
        else
            i++;
        if(k==0)
        {
            cout<< count<<endl;
            return 0;
        }
            
    }
    
    // 답 출력
    cout<<count<<endl;
    
    
    

    
    return 0;
}
