#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    // length of A
    int lth;
    cin>>lth;
    
    // sequence A input
    int A[1001];
    for(int i=0;i<lth;i++)
    {
        cin>>A[i];
    }
    
    // 각 수열의 원소에 대해 자신A[i]보다 앞에 있는 원소A[j]중
    // 자신보다 작은 값 검색해서 
    // 조건에 맞는 수열의 길이 구하고 저장
    int arrSize[1001]; // arrSize[i] == A[i]에 대해 조건에 맞는 수열의 길이
    arrSize[0] = 1;
    int maxSize = 1;
    for(int i=1;i<lth;i++) // 생각의 기준이 되는 자신A[i]
    {
        // A[i]로 만드는 수열의 길이 == A[i]가 마지막으로 오는 가장 긴 증가하는 부분수열의 길이
        int iSize = 0; // 지금까지 가장 긴 길이 초기화 값 0
        for(int j=0;j<i;j++) // 자신보다 앞에 있는 원소 A[j]
        {
            if(A[j]<A[i]) // A[i] 가 A[j]보다 작으면
            {
                if(iSize<arrSize[j]) // 지금까지 가장 긴 길이보다 A[j]까지 가장 긴 길이가 더 길면 
                    iSize = arrSize[j]; // 그 값을 저장한다.
            }
        }
        arrSize[i] = iSize + 1; // 자신의 길이 1을 더한다.
        
        maxSize = max(arrSize[i],maxSize); // 만약 그 길이가 지금까지 최대 길이보다 더 크면 교체한다.
    }
    
    cout<<maxSize<<endl;
    
    
    return 0;
}
