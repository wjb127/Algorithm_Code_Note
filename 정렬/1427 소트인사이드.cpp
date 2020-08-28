#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string n;
    cin>>n;
    
    long long int arr[10]={0,0,0,0,0,0,0,0,0,0};
    
    for(int i=0;i<(int)n.size();i++)
    {
        arr[(int)(n[i] - '0')]++;
    }
    
    for(int i=9;i>=0;i--)
    {
        if(arr[i]>0)
            for(int j=0;j<arr[i];j++)
            {
                cout<<i;
            }
    }
    
    
    
    return 0;
}
