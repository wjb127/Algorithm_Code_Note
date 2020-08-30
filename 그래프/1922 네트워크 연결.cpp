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
#define f(n) for(int i=0;i<n;i++)
#define p(a) cout<<a<<endl;
using namespace std;

int Answer;



int m;
struct DisjointSet;
const int MAX_V = 1001;

// 정점의 개수
int V;
//그래프의 인접 리스트(연결된 정점 번호, 간선 가중치) 쌍을 담는다.
vector<pair<int, int> > ad[MAX_V];


// 유니온 파인드 자료구조 사용
struct DisjointSet {
	vector<int> parent;

	DisjointSet(int n) : parent(n) {
		f(n)
			parent[i] = i;
	}

	// u가 속한 트리의 루트의 번호를 반환한다.
	int find(int u) {
		if (u == parent[u]) return u;
		return find(parent[u]);
	}

	// u가 속한 트리와 v가 속한 트리를 합친다.
	void merge(int u, int v) {
		u = find(u); v = find(v);
		//u와v가 이미 같은 집합에 속하는 경우를 걸러낸다.
		if (u == v) return;

		// u의 루트(==의 부모)를 v의 루트로 교체한다.
		parent[u] = v;
	}
};

// 최소 스패닝 트리
// 정의 : 원래 그래프의 정점 전부와 간선 부분 집합으로 구성된 부분 그래프 + 정점들을 트리형태로 전부 연결 + 가중치 합이 가장 작은 트리

// 크루스칼의 알고리즘 : 모든 간선을 가중치의 오름차순으로 정렬한 뒤, 스패닝 트리에 하나씩 추가(사이클 만드는 경우 배제)

// 프림의 최소 스패닝 트리 알고리즘 : 하나의 시작점으로 구성된 트리에 간선을 하나씩 추가

// 정당성 증명

// 구현

// 크루스칼의 최소스패닝 트리 알고리즘

// 트리를 이용한 상호배제적 집합 구현





// 주어진 그래프에 대해 최소 스패닝 트리에 포함된 간선의 목록을 set에 저장하고,
// 가중치의 합 반환
int kruskal(vector < pair<int, int> >&sel)
{

	// 반환값/최소스패닝트리 초기화
	int ret = 0;
	sel.clear();

	// 가중치(정점1, 정점2)의 목록을 얻는다.
	vector < pair<int, pair<int, int> > > edges;

	// 정점 개수만큼 루프 돌리기
	for (int u=0; u < V; u++) // 시작점 u기준 생각

		// i : 시작점 u에서 연결된 간선들 루프돌기
		f(ad[u].size())
	{
		int v = ad[u][i].first; // u에서 연결된 간선 번호
		int cost = ad[u][i].second; // 가중치

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
		int cost = edges[i].first;

		// 간선의 앞, 뒤 저장
		int u = edges[i].second.first, v = edges[i].second.second;

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
	scanf("%d", &V);
	scanf("%d", &m);

	int a, b, c;
	f(m)
	{
		scanf("%d %d %d", &a, &b, &c);

		ad[a-1].push_back(make_pair(b-1, c));


		
	}

	vector<pair<int,int> > ans;

	printf("%d\n",kruskal(ans));



	return 0;
}
