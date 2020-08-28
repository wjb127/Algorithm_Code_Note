#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;

// maxsum[n] : 계단의 n번째까지 오를 때 최대수
long long int maxsum[301];

// 각 계단에 해당하는 수
long long int stair[301];

int main()
{
    // 계단의 수
    int n;
    cin>>n;
    
    
    // 각 계단에 해당하는 수 입력
    for(int i=0;i<n;i++)
    {
        cin>>stair[i];
    }
    
    // 배열 0으로 초기화
    memset(maxsum,0,sizeof(maxsum));
    
    // 기저 조건
    maxsum[0] = stair[0];
    maxsum[1] = stair[0] + stair[1]; 
    
    // 점화식에 따른 배열 채워넣기
    
    // maxsum[i] 채웠을 때까지 계단을 밟는 경우의 수 2가지
    // 1. i-1번 계단을 안 밟았다 -> i-2번째 계단에서 올라옴 : maxsum[i-2]부터 더하기
    // 2. i-1번 계단을 밟았다. -> i-3번째 계단에서 올라옴 : maxsum[i-3]부터 더하기
    for(int i=2;i<n;i++)
    {
        maxsum[i] = max(maxsum[i-2] + stair[i], maxsum[i-3] + stair[i-1] + stair[i]);
    }
    
    // n번째 계단을 밟을 때 최대값
    cout<<maxsum[n-1]<<endl;
    
    
    
    return 0;
}
