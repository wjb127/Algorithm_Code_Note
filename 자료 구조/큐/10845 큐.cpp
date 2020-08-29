#include<iostream>
#include<memory.h>
#include<algorithm>
#include<string>
using namespace std;

long int queue[10001];

int main()
{
    int n,i=-1,j=-1;
    cin>>n;
    string order;
    
    memset(queue,0,sizeof(queue));
    
    while(n--)
    {
        cin>>order;
        
        if(order == "push")
        {
            int num;
            cin>>num;
            i++;
            queue[i] = num;
            
            if(j==-1)
                j++;
        }
        
        if(order == "front")
        {
            if(j==-1)
                cout<<-1<<endl;
            else
                cout<<queue[j]<<endl;
        }
        
        if(order == "back")
        {
            if(i==-1)
                cout<<-1<<endl;
            else
                cout<<queue[i]<<endl;
        }
        
        if(order == "size")
        {
            
            cout<<i+1<<endl;
        }
        
        if(order == "pop")
        {
            if(j==-1)
                cout<<-1<<endl;
            else
            {
                
                cout<<queue[j]<<endl;
                for(int k=0;k<i;k++)
                {
                    queue[k] = queue[k+1];
                }
                queue[i] = 0;
                i--;
                if(i==-1)
                    j--;
            }
        }
        
        if(order == "empty")
        {
            if(i==-1)
                cout<<1<<endl;
            else
                cout<<0<<endl;
        }
        
    }
    
    
    
    
    
    
    return 0;
}
