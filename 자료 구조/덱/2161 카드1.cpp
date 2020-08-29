#include<iostream>
#include<cstdio>
#include<algorithm>
#include<memory.h>
using namespace std;

int card[1001];
int Bin[1001];

int n;
int binnum = 1;

void dump();
void skip();

int main()
{
    memset(card,0,sizeof(card));
    memset(Bin,0,sizeof(Bin));
    
    
    scanf("%d",&n);
    
    int _n=n;
    
    for(int i=1;i<=n;i++)
    {
        // 카드 초기화 시키기
        card[i] = i;
    }
    
    // 카드가 다 없어질 때까지
    while(card[1]!=0)
    {
        // 버리기
        dump();
        // 넘기기
        skip();
    }
    
    for(int i=1;i<=_n;i++)
    {
        // 답 출력
        printf("%d ",Bin[i]);
    }
    
    
    
    
    return 0;
}

void dump()
{
    
    int tmp = card[1];
    
    // 버리고 binnum 세팅
    Bin[binnum] = tmp;
    binnum++;
    
    // 카드 앞으로 땡기기
    n--;
    for(int i=1;i<=n;i++)
    {
        card[i] = card[i+1];
    }
    card[n+1]=0;
    
}

void skip()
{
    // 그냥 뒤로 밀어넣기
    int tmp = card[1];
    
    if(tmp==0)
        return;
    
    for(int i=1;i<n;i++)
    {
        card[i] = card[i+1];
    }
    card[n] = tmp;
}
