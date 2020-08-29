#include<iostream>
#include<algorithm>
#include<memory.h>
#include<queue>
using namespace std;



// 방문된 곳 표시
int visited[200001];
queue<int> visit;


int main()
{
    int n,k;
    cin>>n>>k;
    
    memset(visited,0,sizeof(visited));
    
    
    
        
    
    visit.push(n);
    visited[n] = 1;
    
    while(!visit.empty())
    {
        int past = visit.front();
        visit.pop();
        
        
            if(past-1>=0 )
            if(visited[past-1]==0)
            {
                
                visit.push(past-1);
                visited[past-1] = visited[past] + 1;
                
                //cout<<past-1<<" "<<visited[past-1]<<endl;
                
            }
            if(past+1<=k && past+1<=200000)
            if(visited[past+1]==0)
            {
                
                visit.push(past+1);
                visited[past+1] = visited[past] + 1;
                
                //cout<<past+1<<" "<<visited[past+1]<<endl;
                
            }
        // 엉엉ㅠㅠ 내가 왜 큰수에서 빼가며 정답에 근접하는 경우의 수를 생각 못했지? ㅠㅠ
            if(past*2<=200000)
            if(visited[past*2]==0)
            {
                
                visit.push(past*2);
                visited[past*2] = visited[past] + 1;
                
                //cout<<past*2<<" "<<visited[past*2]<<endl;
                
            }
        if(visited[k])
            break;
        
        
                
            
    }
    
    
    
    
    
    cout<<visited[k]-1<<endl;
    
    
    
    
    
    
    return 0;
}
