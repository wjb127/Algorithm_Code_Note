#include<iostream>
#include<cstdio>
#include<memory.h>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
#define f(n) for(int i=0;i<n;i++)
#define p(a) cout<<a<<"\n"
using namespace std;

int N;
int main() {

	cin >> N;

	int x;
	vector<int> arr;
	f(N) {
		cin >> x;

		arr.push_back(x);

	}

	sort(arr.begin(), arr.end());

	f(N) {

		p(arr[N-i-1]);
	}



	return 0;
}
