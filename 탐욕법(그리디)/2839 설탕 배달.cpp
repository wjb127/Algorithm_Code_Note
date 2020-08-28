#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;

int main()
{
    int N,a,b;
    cin>>N;
    
    for(int b = N/5 ; b>=0 ; b--)
    {
        if(b == 0 && N%3 != 0)
        {
            cout<<-1<<endl;
            return 0;
        }
        
        a = (N - 5*b)/3;
        
        if((N - 5*b)%3 == 0)
        {
            cout<<a+b<<endl;
            return 0;
        }
            
        
    }
    
    
    
    return 0;
}
