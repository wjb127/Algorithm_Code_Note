#include<iostream>
#include<memory.h>
#include<algorithm>
using namespace std;

struct Time {
    
    int st,ed;
};

const int INF = 9876543210;
int N;
Time meet[100001];

bool cmp(Time a, Time b) {
    
    if(a.ed < b.ed) return true;
    if(a.ed > b.ed) return false;
    return a.st < b.st;
}


int main()
{
    cin>>N;
    
    memset(meet,INF,sizeof(meet));
    
    for(int i=0;i<N;i++) {
        cin>> meet[i].st>>meet[i].ed;
    }
    
    sort(meet,meet+N,cmp);
    
    int ans = 1;
    int decide = meet[0].ed;
    for(int i=1;i<N;i++) {
        if(decide <= meet[i].st) {
            ans++;
            decide = meet[i].ed;
        }
    }
    cout<<ans<<endl;
    
    
    
    return 0;
}
