#include<cstdio>
#include<memory.h>
#include<algorithm>
using namespace std;

long long int arr[2000001];

int main()
{
    memset(arr,0,sizeof(arr));
    
    int n;
    scanf("%d",&n);
    for(long long int i=0;i<n;i++)
    {
        int input;
        scanf("%d",&input);
        // 음수도 고려하기
        arr[input+1000000]++;
    }
    
    int i=0,j=0;
    while(j<n)
    {
        if(arr[i]!=0)
        {
            printf("%d\n",i - 1000000);
            j++;
        }
        i++;
    }
    
    
    
    return  0;
}
