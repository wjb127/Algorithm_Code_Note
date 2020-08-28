#include<iostream>
#include<memory.h>
#include<algorithm>
using namespace std;

// 각 집에 색칠하는 색깔당 비용
long int house[1001][3];
long int minCost[1001][3];

int main()
{
    // 집 개수
    int n;
    cin>>n;
    
    // 비용 할당
    for(int i=0;i<n;i++)
    {
        cin>>house[i][0]>>house[i][1]>>house[i][2];
    }
    
    //기저 조건
    minCost[0][0] = house[0][0];
    minCost[0][1] = house[0][1];
    minCost[0][2] = house[0][2];
    
    // i번째 집에 j색을 골랐을 때 minCost[i][j]를 구하는 법
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            minCost[i][j] 
                = min(house[i][j] + minCost[i-1][(j+1)%3],house[i][j] + minCost[i-1][(j+2)%3]);
        }
    }
    
    int ans = min(min(minCost[n-1][0],minCost[n-1][1]),minCost[n-1][2]);
    
    cout<<ans<<endl;
    
    
    
    return 0;
}
