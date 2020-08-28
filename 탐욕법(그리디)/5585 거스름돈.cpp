#include<iostream>
using namespace std;

int main()
{
    int price;
    cin>>price;
    
    int change = 1000 - price;
    
    int num=0;
    
    num += change/500;
    change -= (change/500)*500; // 500처리
    
    num += change/100;
    change -= (change/100)*100; // 100처리
    
    num += change/50;
    change -= (change/50)*50; // 50처리
    
    num += change/10;
    change -= (change/10)*10; // 10처리
    
    num += change/5;
    change -= (change/5)*5; // 5처리
    
    num += change/1;
    change -= (change/1)*1; // 1처리
    
    cout<<num<<endl;
    
    
    return 0;
}
