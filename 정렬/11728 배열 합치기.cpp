#include<iostream>
#include<cstdio>
#include<algorithm>
#include<memory.h>
using namespace std;

long long int A[2000001],B[1000001],C[1000001];

int main()
{
    long long int n,m;
    scanf("%lld %lld",&n, &m);
   
    
    for(long long int i=0;i<n;i++)
        scanf("%lld",&A[i]);    

    for(long long int j=n;j<n+m;j++)
        scanf("%lld",&A[j]);
    
     
    sort(A,A+n+m);
    
    for(long long int k=0;k<n+m;k++)
        printf("%lld ",A[k]);
        
        
    
    
    
    
    
    return 0;
}

