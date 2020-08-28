#include<iostream>
#include<memory.h>
#include<algorithm>
#include<string>
using namespace std;


string N;
int arr[100001];
bool zero = false;
bool make3 = false;

int main()
{
    cin>>N;
    
    int sum=0;
    for(int i=0;i<(int)N.size();i++) {
        arr[i] = N[i] - '0';
        sum+=arr[i];
        if(arr[i] == 0) {
            zero = true;
        }
            
    }
    if(sum%3 == 0)
        make3 = true;
    
    if(zero && make3) {
        sort(arr,arr+(int)N.size());
        for(int i=(int)N.size()-1;i>=0;i--) {
            cout<<arr[i];
        }
    }
    else {
        cout<<-1<<endl;
    }
    
    return 0;
}
