#include<iostream>
#include<memory.h>
#include<algorithm>
#include<cstdlib>
using namespace std;


int main()
{
    int T,N,M;
    
    // 테스트케이스
    cin>>T;
    
    for(int i=0;i<T;i++)
    {
        // 동전 개수
        cin>>N;
        // 동전 종류
        int*price = new int[N];
        
        for(int j=0;j<N;j++)
        {
            cin>>price[j];
        }
        
        int sum; // 최종 금액합계
        cin>>sum;
        
        int Case[10001]; // Case[i] = 금액합계 i를 만드는 경우의 수
        memset(Case,0,sizeof(Case));
        
        for(int j=0;j<N;j++) // 현재코인 price[j] 선택
        {
            Case[price[j]]++; // 현재코인 price[j]로 금액합계 price[j]를 만드는 경우의 수
            
            for(int k=price[j]+1;k<=sum;k++) // 현재코인보다 큰 금액합계 탐색
            {
                // 새로운 금액합계 k를 만드는 경우의 수를 갱신한다
                // 금액합계 (k - 현재코인)를 만드는 경우의 수에
                // 지금까지의 금액합계 k를 만드는 경우의 수를 더하는 방식으로
                Case[k] = Case[k - price[j]] + Case[k];
            }
        }
        
        // 답 출력
        cout<<Case[sum]<<endl;
        
        // 동적 배열 해제
        delete [] price;
    }
    
    
    return 0;
}
