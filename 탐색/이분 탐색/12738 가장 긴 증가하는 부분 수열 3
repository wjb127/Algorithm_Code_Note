#include<iostream>
#include<algorithm>
#include<memory.h>
#include<vector>
using namespace std;

long long int INF = 1000000000;

vector<long long int> semi;
vector<long long int>::iterator it;
long long int n;
long long int tmp;

int main()
{
    // cin가속
    cin.sync_with_stdio(false);
    
    // 개수 입력
    cin>>n;
    if(n<=1)
    {
        cout<<n<<endl;
        return 0;
    }
    
    
    semi.push_back(INF);
    int ans = 1;
    semi.reserve(n+1);
    
    // n개 입력받기
    for(long long int i=0;i<n;i++)
    {
        cin>>tmp;
        
        // 만약 현재 가장 큰 것보다 크면 (길이 늘리면서) 원소 추가
        if(semi.back() < tmp)
        {
            semi.push_back(tmp);
            ans++;
        }
        // 만약 현재 가장 큰 것보다 작다면
        else
        {
            auto it = lower_bound(semi.begin(), semi.end(), tmp);
            *it = tmp;
        }
        
        
    }



    
    // 벡터 사이즈는 최장증가부분수열의 길이 이므로
    // n에서 빼면 구하는 답이 된다
    cout<<ans<<"\n";
    
    
    return 0;
}
