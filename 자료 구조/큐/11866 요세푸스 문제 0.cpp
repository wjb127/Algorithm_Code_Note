#include<iostream>
#include<memory.h>
#include<algorithm>
#include<list>
using namespace std;

int n,m;

int arr[5001];

int main()
{
    cin>>n>>m;
    
    // 링크드 리스트로 구현
    list<int> seq;
    
    for(int i=1;i<=n;i++)
    {
        seq.push_back(i);
    }
    
    list<int>::iterator kill = seq.begin();
    
    for(int i=0;i<m-1;i++)
        kill++;
    
    for(int i=0;i<n;i++)
    {
        arr[i] = *kill;
        kill = seq.erase(kill);
        if(kill == seq.end())
            kill = seq.begin();
        
        for(int j=0;j<m-1;j++)
        {
            kill++;
            if(kill == seq.end())
                kill = seq.begin();
        }
        
        
    }
    
    
    cout<<"<";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
        if(i!=n-1)
            cout<<", ";
    }
    cout<<">"<<endl;
    
    return 0;
}
