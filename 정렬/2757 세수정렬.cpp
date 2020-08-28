#include<iostream>
#include<memory.h>
#include<algorithm>
using namespace std;

#define f(n) for(int i=0;i<n;i++)
#define p(a) cout<<a<<endl

int main()
{
	
	int arr[4];
	
	cin>>arr[0]>>arr[1]>>arr[2];

	sort(arr,arr+3);

	cout << arr[0] <<" "<< arr[1] <<" "<< arr[2] <<endl;

	return 0;
}
