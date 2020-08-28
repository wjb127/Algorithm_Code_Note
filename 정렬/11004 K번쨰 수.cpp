#include<iostream>
#include<cstdio>
#include<algorithm>
#include<memory.h>
using namespace std;

long long int n,k;
long long int arr[5000001];

int main()
{
    scanf("%lld %lld",&n,&k);
    
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
    }
    
    sort(arr,arr+n);
    
    
    printf("%lld",arr[k-1]);
    
    return 0;
}
