#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;
// 변수 설정 주의@
long int num[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // 수의 개수 입력받기 < 10000000
    long long int n;
    cin >> n;

    // 매개 수치 < 10000
    long long int media = 0;

    // 숫자 입력받을 배열 -> 인덱스로 입력받기!!! (n이 존나 클 수도 있기 때문 ㅋㅋ)

    //memset(num,0,sizeof(num));

    // 입력 반복문
    for (int i = 0; i < n; i++)
    {
        // 수를 입력받으면
        cin >> media;
        // 인덱스 값으로 받아서 해당하는 수의 배열에 받았다는 표시를 한다.
        num[media]++;
    }

    for (int i = 1; i < 10001; i++)
    {
        if (num[i] > 0)
        {
            for (int j = 0; j < num[i]; j++)
            {
                cout << i << "\n";
            }
        }
    }




    return 0;
}
