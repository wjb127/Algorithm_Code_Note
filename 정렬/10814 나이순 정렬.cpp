#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector <pair<int,string> > Set;

bool cmp(const pair<int,string> &x, const pair<int,string> &y)
{
    if(x.first < y.first)
    {
        return true;
    }
    
    else
        return false;
}

int main()
{
    long long int n;
    cin>>n;
    
    Set.resize(n);
    
    for(int i=0;i<n;i++)
    {
        int age;
        string name;
        cin>>age>>name;
        
        Set[i].first = age;
        Set[i].second = name;
        
    }
    
    stable_sort(Set.begin(),Set.end(),cmp);
    
    for(int i=0;i<n;i++)
    {
        cout<<Set[i].first<<" "<<Set[i].second<<endl;
    }
    
    
    
    
    return 0;
}
