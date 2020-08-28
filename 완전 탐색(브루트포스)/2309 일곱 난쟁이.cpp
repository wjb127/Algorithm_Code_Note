#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;

int main()
{
    // 난쟁이 키 입력받기!
    // 난쟁이 키의 합 구하기!
    int dwf[10];
    int sum=0;
    for(int i=0;i<10;i++)
    {
        cin>>dwf[i];
        sum+=dwf[i];
    }
    
    
    int fake[2];
    for(int i=0;i<10;i++)
    {
        // 합에서 키 빼기
        int tmp = sum - dwf[i];
        // 
        for(int j=i+1;j<10;j++)
        {
            if(tmp - dwf[j] == 100)
            {
                fake[0] = i;
                fake[1] = j;
            }
        }
    }
    
    dwf[fake[0]] = 0;
    dwf[fake[1]] = 0;
    
    sort(dwf,dwf+10);
    
    for(int i=0;i<10;i++)
    {
        if(dwf[i]!=0)
            cout<<dwf[i]<<endl;
    }
    
    
    
    return 0;
}
