#include<iostream>
#include<algorithm>
#include<memory.h>
#include<vector>
using namespace std;

vector<int> semi;
vector<int>::iterator it;
int n;
int tmp;

int main()
{
    // cin가속
    cin.sync_with_stdio(false);
    
    // 개수 입력
    cin>>n;
    // 일단 semi에 저장
    semi.push_back(n);
    
    // n개 입력받기
    for(int i=0;i<n;i++)
    {
        cin>>tmp;
        
        // 만약 현재 가장 큰 것보다 크면 (길이 늘리면서) 원소 추가
        if(semi.back() < tmp)
        {
            semi.push_back(tmp);
        }
        // 만약 현재 가장 큰 것보다 작다면
        else
        {
            // 벡터 탐색하면서
            for(it=semi.begin();it!=semi.end();it++)
            {
                // 더 작은 원소가 나타났을 때 그것 대신 저장하고 탐색 종료
                // 만약 이것이 맨 마지막 원소대신 저장되었다면 
                // 이 행위는 기존 벡터를 연장 가능하게 만드는 행위임
                if(*it > tmp)
                {
                    *it = tmp;
                    break;
                }
            }
        }
        
        
    }
    
    
    // 벡터 사이즈 : 
    cout<<semi.size()<<"\n";
    
    
    return 0;
}
