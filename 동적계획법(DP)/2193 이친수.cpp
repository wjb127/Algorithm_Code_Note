#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;

long int arr[91][2];

long int f(int n, int x)
{
    
    
    if(arr[n][x]!=0)
        return arr[n][x];
    
    if(n<=2)
        return arr[n][x];
    
    
    if(x==0)
        return arr[n][x] = f(n-1,0) + f(n-1,1);
    else
        return arr[n][x] = f(n-1,0);
       
}

int main()
{
    int n;
    cin>>n;
    
    memset(arr,0,sizeof(arr));
    //for(int i=0;i<91;i++)
    //{
    //   arr[i][0] = 0;
    //   arr[i][1] = 0;
    //}
    
    arr[1][1] = 1;
    arr[2][0] = 1;
    
    cout<<f(n,0) + f(n,1)<<endl;
    
    return 0;
}
