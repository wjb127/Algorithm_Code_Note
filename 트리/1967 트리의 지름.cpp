#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<ctime>
#include<queue>
#include<memory.h>
#pragma warning(disable: 4996)
#define p(a) cout<<a<<endl
#define f(n) for(int i=0;i<n;i++)
#define pb push_back
using namespace std;

int v;

// 인접 리스트 
vector<pair<int, int> > tree[100001];
int arr[100001];

priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> target;


int dfs(int n)
{
	arr[n] = 1;
	//cout << n <<" : "<< (int)tree[n].size() << endl;
	int ans = 0;


	for (int i = 0; i < (int)tree[n].size(); i++)
	{

		// 표시가 안되어 있는 경우
		if (arr[tree[n][i].first] == 0)
		{

			arr[tree[n][i].first] = 1;
			// 각 정점에 대해서 최대한 깊숙히 들어간다
			target.push(make_pair(ans, tree[n][i].first));
			ans = dfs(tree[n][i].first) + tree[n][i].second;
			// ans += dfs(tree[n][i])+1;

		}


	}

	return ans;
}

int dfs2(int n)
{
	arr[n] = 1;
	//cout << n <<" : "<< (int)tree[n].size() << endl;
	int ans = 0;


	// n번 노드에 연결된 정점을 모두 돈다
	for (int i = 0; i < (int)tree[n].size(); i++)
	{

		// 표시가 안되어 있는 경우
		if (arr[tree[n][i].first] == 0)
		{
			//ans++;
			arr[tree[n][i].first] = 1;
			// 각 정점에 대해서 최대한 깊숙히 들어간다
			ans = dfs2(tree[n][i].first) + tree[n][i].second;
			// ans += dfs(tree[n][i])+1;
			//p(ans);


		}


	}

	return ans;
}

int l = 0;
int e = 0;

void dfs3(int n, int length)
{
	arr[n] = 1;

	if (l < length)
	{
		l = length;
		e = n;
	}

	// n번 노드에 연결된 정점을 모두 돈다
	for (int i = 0; i < (int)tree[n].size(); i++)
	{
		// 표시가 안되어 있는 경우
		if (arr[tree[n][i].first] == 0)
		{
			// 각 정점에 대해서 최대한 깊숙히 들어간다
			dfs3(tree[n][i].first, length + tree[n][i].second);
		}
	}
}

int main()
{
	memset(arr, 0, sizeof(arr));


	// 2 <= 트리 정점의 개수 받기 <= 100000 -> O(nlgn) 이하로 만들기
	cin >> v;


	// 간선의 정보 입력받기 : 정점번호, 정점까지의 거리 - 마직막에는 -1 입력받기
	// 1 <= 주어지는 거리 <= 10000
	int spotNum, connected, dist;
	f(v-1)
	{
		// 일단 정점 번호를 입력받고
		cin >> spotNum;
		
		// 정점번호를 입력받고
		cin >> connected;
		// 거리 입력받기
		cin >> dist;

		// 자료구조를 통하여 간선의 정보들 저장하기
		tree[spotNum].pb(make_pair(connected, dist));
		tree[connected].pb(make_pair(spotNum, dist));
		

	}


	// 그 자료 내에서 트리의 지름 계산하기
	// 계산 메커니즘 
	// 1. 1번 노드에서부터 dfs를 통해 가장 깊은 곳(= 거리가 먼 곳)을 탐색함
	// 2. 이 곳은 구하고자 하는 지름의 한 쪽 끝이다
	// 3. 이 곳에서 dfs를 해서 도착한 가장 깊은 곳은 지름의 반대쪽 끝이다.

	/*f(v)
	{
		cout << i + 1 << " : ";

		for (int j = 0; j < (int)tree[i+1].size(); j++)
		{
			cout << tree[i+1][j].first << " ";
		}
		p("");
		
	}*/

	dfs3(1, 0);

	memset(arr, 0, sizeof(arr));
	l = 0;

	dfs3(e, 0);

	cout << l << endl;





	return 0;
}
