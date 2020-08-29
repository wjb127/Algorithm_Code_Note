#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;

int arr[201];
// n번째 아이까지 가장 긴 증가하는 부분 수열의 길이
int len[201];



int main()
{
    // 아이들의 수
    int n;
    cin>>n;
    
    // 아이들의 섞인 순서
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    // 가장 긴 증가하는 부분 수열을 구하기 (LIS로 풁기!!)
    
    // 경우의 수들을 
    
    memset(len,0,sizeof(len));
    len[0] = 1; // 자신의 길이
    int ans = 0; // 답
    
    // 1. 현재 아이 arr[i]를 선택
    for(int i=0;i<n;i++)
    {
        // arr[i] 앞의 아이들 검색
        // 가장 긴 증가하는 부분 수열(번호들의 수열)의 길이를 0으로 초기화
        int maxlen = 0;
        // 현재 아이 앞 번호 검색
        for(int j=0;j<i;j++)
        {
            // 앞 번호중 작은 아이들 검색
            if(arr[j] < arr[i])
                // 앞 번호까지 만들어지는 가장 긴 증가하는 부분 수열의 길이 갱신
                if(len[j] > maxlen)
                {
                    maxlen = len[j];
                }
        }
        
        // 현재아이까지 만들어지는 가장 긴 증가하는 부분 수열의 길이 만들기(+1)
        len[i] = maxlen + 1;
        
        // 답은 최대 길이가 되어야 함
        ans = max(len[i],ans);
    }
    
    int realAns = n - ans;
    
    cout<<realAns<<endl;
    
    
    return 0;
}
