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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	cin >> a >> b;

	vector<string> A(a);
	
	f(a)
		cin >> A[i];

	sort(A.begin(), A.end());

	string str;
	vector<string> answer;
	f(b) {
		cin >> str;
		int exist = 0;
		if (binary_search(A.begin(), A.end(), str)) {
			exist = 1;
			
		}
		if (exist == 1) {
			answer.push_back(str);
		}
		
	}

	sort(answer.begin(), answer.end());

	p(answer.size());

	f((int)answer.size())
		p(answer[i]);




	return 0;
}
