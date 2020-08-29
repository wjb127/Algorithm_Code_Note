#include<iostream>
#include<cstdio>
#include<algorithm>
#include<memory.h>
#include<cstring>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    
    char str[51];

    for(int i=0;i<n;i++)
    {
        scanf("%s",str);
        
        int len = strlen(str);
        
        int bsk[51];
        int bsknum=0;
        memset(bsk,0,sizeof(bsk));
        
        for(int i=0;i<len;i++)
        {
            if(i>0 && bsk[bsknum-1]==1 && str[i]==')')
            {
                bsk[bsknum-1]=0;
                bsknum--;
            } 
            else if(str[i]==')')
            {
                bsk[bsknum]=2;
                bsknum++;
            }
            else if(str[i]=='(')
            {
                bsk[bsknum]=1;
                bsknum++;
            }
            
        }
        if(bsk[0]==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    
    return 0;
}
