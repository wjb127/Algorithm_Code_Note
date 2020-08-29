#include <iostream>
#include <algorithm>
#include<memory.h>
using namespace std;

int dp[1002][1002];

int main()
{
    string s1;
    string s2;
 
    cin >> s1;
    cin >> s2;

    memset(dp,0,sizeof(dp));
 
    int len1 = s1.length();
    int len2 = s2.length();
 
    for(int i=0; i<len2; i++) 
      for(int j=0; j<len1; j++) 
       //같을 때 
       if(s2[i] == s1[j]) 
            dp[i+1][j+1] = dp[i][j] + 1;
       // 다를 때
       else 
           dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
   
     cout<<dp[len2][len1]<<endl;
}
