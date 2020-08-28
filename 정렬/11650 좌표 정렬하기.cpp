#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

// 좌표의 개수
int n;

// 좌표
vector <pair<int, int> > pos;
typedef pair<int, int> P;

// 비교함수 : 뒤쪽 좌표의 x,y가 클 경우 참, 아니면 거짓
// 참일 때 swap!
bool cmp(const P &u, const P &v)
{
    // x좌표 비교
    if (u.first < v.first)
        return true;
    else if (u.first == v.first)
    {
        return u.second < v.second;
    }
    else
    {
        return false;
    }
}

int main()
{
    // 좌표의 개수 n 입력받기
    scanf("%d", &n);
    
    // 좌표받는 벡터 리사이즈
    pos.resize(n);
    
    // xy좌표 입력받기
    for (int i = 0; i < n; i++)
    {
        // 매개 변수를 통해 입력받기
        int u, v;
        scanf("%d %d", &u, &v);
        pos[i].first = u;
        pos[i].second = v;
    }
    
    // cmp 조건으로 정렬하기 @@@@@
    sort(pos.begin(), pos.end(), cmp);
    
    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", pos[i].first, pos[i].second);
    }
}
