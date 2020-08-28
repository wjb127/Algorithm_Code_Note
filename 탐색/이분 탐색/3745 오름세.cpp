#include<iostream>
#include<cstdio>
#include<algorithm>
#include<memory.h>
#include<vector>
using namespace std;


int main()
{
    
        
        
    int n;
    while(cin>>n)
    {
        
   
        int arr[100001], dp[100001];
        
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		dp[0] = arr[0];
		int pos, size = 0;
		for (int i = 1; i < n; i++) {
			if (dp[size] < arr[i]) {
				dp[++size] = arr[i];
				continue;
			}
			pos = lower_bound(dp, dp + size, arr[i]) - dp;
			dp[pos] = arr[i];
		}
		cout << size + 1 << '\n';



       
    }
    
    return 0;
}
