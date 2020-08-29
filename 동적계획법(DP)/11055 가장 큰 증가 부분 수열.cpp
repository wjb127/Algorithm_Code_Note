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
    // 조건에 맞는 수열의 합 구하고 저장
    int arrSum[1001]; // arrSum[i]까지 조건에 맞는 수열의 합
    arrSum[0] = A[0];
    int maxSum = 0;
    for(int i=0;i<lth;i++) // 생각의 기준이 되는 자신A[i]
    {
        
        int iSum = 0; // 지금까지 가장 긴 합 == A[i]에 더할 값
        for(int j=0;j<i;j++) // 자신보다 앞에 있는 원소 A[j]
        {
            if(A[j]<A[i]) // A[i] 가 A[j]보다 크면
            {
  
                iSum = max(arrSum[j],iSum); // 더할 값은 바뀐다.
                
            }
        }
        arrSum[i] = iSum + A[i];
        
        maxSum = max(arrSum[i],maxSum); // 만약 그 길이가 지금까지 최대 길이보다 더 크면 교체한다.
    }
    
    cout<<maxSum<<endl;
    
    
    return 0;
}
