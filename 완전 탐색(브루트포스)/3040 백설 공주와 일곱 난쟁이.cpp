#include<iostream>
#define f(n) for(int i=0;i<n;i++)
#define p(a) cout<<a<<endl
using namespace std;

int main()
{
    int dwf[10];
    int sum=0;
    
    

    f(9)
    {
         cin>>dwf[i];
         sum+=dwf[i];
    }
    
    int D;
    int x=0,y=0;
    f(9)
    {
        D = sum - dwf[i];
        
        
        for(int j=0;j<9;j++)
        {
            if(D - dwf[j] == 100)
            {
            x=i;
            y=j;
            break;
            }
            
        }
    if(D - dwf[y] == 100)
        break;
    }
    f(9)
    {
        if(i!=x && i!=y)
        p(dwf[i]);
        
    }
    
    
    return 0;
}
 
