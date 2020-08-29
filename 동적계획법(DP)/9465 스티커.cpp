#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;

int t;

int n;

int arr[3][100001];

int cache[3][100001];



int sticker(int n, int index)
{
    int ret=0;
    //cout<<index<<endl;
    
    if(n==0)
    {
        if(index==1)
        	return arr[2][0];
        if(index==2)
            return arr[1][0];
        if(index==0)
            return max(arr[1][0],arr[2][0]);
        	
    }
    
    if(cache[index][n]!=-1)
        return cache[index][n];
    
    for(int i=0;i<3;i++)
    {
    	if(index!=i)
    	    ret = max(ret, arr[i][n]+sticker(n-1,i));
    }
	
	
	
    return cache[index][n]=ret;
}

int main()
{
    
        // 웬만하면 memset도 쓰지 말자
        //memset(cache,-1,sizeof(cache));
    
    
        cin>>t;
        for(int i=0;i<t;i++)
        {
            cin>>n;
            for(int j=0;j<n;j++)
            {
                arr[0][j] = 0;
                cache[0][j] = -1;
            }
            for(int j=0;j<n;j++)
            {
                cin>>arr[1][j];
                cache[1][j] = -1;
            }
            for(int j=0;j<n;j++)
            {
                cin>>arr[2][j];
                cache[2][j] = -1;
            }
            
            
            int num = max(sticker(n-1, 1),sticker(n-1,2));
            
                cout<<num<<endl;
            
        }
        

    
    
    return 0;
}
