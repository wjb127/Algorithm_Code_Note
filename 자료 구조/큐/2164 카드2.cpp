#include<cstdio>
#include<queue>
using namespace std;

// 카드에 적당한 자료구조 큐 활용
queue<int> q;

int main()
{
    // 카드의 개수 입력
    int n;
    scanf("%d",&n);
    
    // 큐에 카드 초기화
    for(int i = 1 ; i <= n ; i++) 
    {
        q.push(i);
    }
 
    // 시뮬레이션
    while(true)
    {
        // 만약 카드가 한 장 남았다면
        if(q.size() == 1)
        {
            // 그 카드를 출력하고
            printf("%d",q.front());
            // 반복문 종료
            break;
        }
        // 아니라면 일단 한 장 버리고
        q.pop();
        // 맨 앞의 카드 한 장을 저장한 뒤에
        int back = q.front(); 
        // 그 카드를 버리면서
        q.pop(); 
        // 저장한 값을 큐에 넣는 방식으로 버린 카드를 맨 뒤로 가져옴
        q.push(back);
    }
    return 0;
}
