#include<iostream>
#include<memory.h>
using namespace std;

long long int arr[1001][3];

long long int T(int n, int x)
{
    // 기저조건
    if(n==1 || n==2)
        return arr[n][x]; // 미리 채워놓고 출력
    
    
    // 메모이제이션 확인
    if(arr[n][x]!=0)
        return arr[n][x];
    
    // 메모이제이션이 안 되어 있을 때
    if(x==0)
        return arr[n][0] = (T(n-1,0) + T(n-1,1) + T(n-1,2))%10007;
    if(x==1)
        return arr[n][1] = (T(n-2,0) + T(n-2,1) + T(n-2,2))%10007;
    if(x==2)
        return arr[n][2] = (T(n-2,0) + T(n-2,1) + T(n-2,2))%10007;
}


int main()
{
    int n;
    cin>>n;
    
    memset(arr,0,sizeof(arr));
   
    arr[1][0] = 1;
    arr[1][1] = 0;
    arr[1][2] = 0;
    
    arr[2][0] = 1;
    arr[2][1] = 1;
    arr[2][2] = 1;
    
    cout<<(T(n,0)+T(n,1)+T(n,2))%10007<<endl;
    
    return 0;
}
