#include<iostream>
#include<algorithm>
#include<memory.h>
#include<vector>
#include<string>
#include<map>
#include<list>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#pragma warning(disable: 4996)
#define f(n) for(long long int i=0;i<n;i++)
#define p(a) cout<<a<<endl;
using namespace std;

long long int m;
struct DisjointSet;
const long long int MAX_V = 10001;

// 정점의 개수
long long int V;
//그래프의 인접 리스트(연결된 정점 번호, 간선 가중치) 쌍을 담는다.
vector<pair<long long int, long long int> > ad[MAX_V];


// 유니온 파인드 자료구조 사용
struct DisjointSet {
	vector<long long int> parent;

	DisjointSet(long long int n) : parent(n) {
		f(n)
			parent[i] = i;
	}

	// u가 속한 트리의 루트의 번호를 반환한다.
	long long int find(long long int u) {
		if (u == parent[u]) return u;
		return find(parent[u]);
	}

	// u가 속한 트리와 v가 속한 트리를 합친다.
	void merge(long long int u, long long int v) {
		u = find(u); v = find(v);
		//u와v가 이미 같은 집합에 속하는 경우를 걸러낸다.
		if (u == v) return;

		// u의 루트(==의 부모)를 v의 루트로 교체한다.
		parent[u] = v;
	}
};


// 주어진 그래프에 대해 최소 스패닝 트리에 포함된 간선의 목록을 set에 저장하고,
// 가중치의 합 반환
long long int kruskal(vector < pair<long long int, long long int> >&sel)
{

	// 반환값/최소스패닝트리 초기화
	long long int ret = 0;
	sel.clear();

	// 가중치(정점1, 정점2)의 목록을 얻는다.
	vector < pair<long long int, pair<long long int, long long int> > > edges;

	// 정점 개수만큼 루프 돌리기
	for (long long int u = 0; u < V; u++) // 시작점 u기준 생각

		// i : 시작점 u에서 연결된 간선들 루프돌기
		f(ad[u].size())
	{
		long long int v = ad[u][i].first; // u에서 연결된 간선 번호
		long long int cost = ad[u][i].second; // 가중치

		// 함수 내에서 만든 간선 벡터에 저장
		edges.push_back(make_pair(cost, make_pair(u, v)));

	}

	// 가중치 순 정렬
	sort(edges.begin(), edges.end());

	// 처음엔 모든 정점이 서로 분리되어 있다.
	DisjointSet sets(V);

	// 간선 수만큼 루프 돌면서
	f(edges.size())
	{

		// 간선 u-v검사

		// 간선 가중치
		long long int cost = edges[i].first;

		// 간선의 앞, 뒤 저장
		long long int u = edges[i].second.first, v = edges[i].second.second;

		// 이미 u-v연결시 무시
		if (sets.find(u) == sets.find(v)) continue;

		// 이 둘을 합친다. : 간선으로 연결한다
		sets.merge(u, v);

		// 트리에 간선정보 저장한다
		sel.push_back(make_pair(u, v));

		// 반환값에 간선 가중치를 더한다
		ret += cost;

	}
	return ret;
}


int main()
{
	scanf("%lld %lld", &V,&m);
	//scanf("%d", &m);

	long long int a, b, c;
	f(m)
	{
		scanf("%lld %lld %lld", &a, &b, &c);

		ad[a - 1].push_back(make_pair(b - 1, c));



	}

	vector<pair<long long int, long long int> > ans;

	printf("%lld\n", kruskal(ans));



	return 0;
}
