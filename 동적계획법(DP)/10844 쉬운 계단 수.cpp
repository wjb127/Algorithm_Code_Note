#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;

long long int arr[101][10];

long long int stair(int n,int x)
{
    if(arr[n][x]!=0)
        return arr[n][x];
    
    if(n==1)
        return arr[1][x];
    
    if(x==0)
        return arr[n][x] = stair(n-1,1) % 1000000000;
    if(x==9)
        return arr[n][x] = stair(n-1,8) % 1000000000;
    
    return arr[n][x] = (stair(n-1,x-1) + stair(n-1,x+1) ) % 1000000000;
    
}

int main()
{
    memset(arr,0,sizeof(arr));
    
    for(int i=1;i<=9;i++)
        arr[1][i] = 1;
    
    int n;
    cin>>n;
    
    cout<<(stair(n,0)+stair(n,1)+stair(n,2)+stair(n,3)+stair(n,4)+stair(n,5)+stair(n,6)
        +stair(n,7)+stair(n,8)+stair(n,9)) % 1000000000<<endl;
    
    
    
    return 0;
}
