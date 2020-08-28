#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
 
// 비교함수를 자체적으로 개발하여 sorting
bool cmp(const pair<int,int> &a, const pair<int,int>&b)
{
    if(a.second<b.second)
        return true;
    else if(a.second == b.second)
        return a.first <b.first;
    else
    return false;
}
 
int main()
{
    int n;
    
    scanf("%d",&n);
 
    vector<pair<int, int>> a(n);
 
    for(int i=0; i<n; i++)
        scanf("%d %d",&a[i].first, &a[i].second);
 
    sort(a.begin(),a.end(),cmp);
 
    for(int i=0; i<n; i++)
        printf("%d %d\n",a[i].first, a[i].second);
    
    return 0;
}

