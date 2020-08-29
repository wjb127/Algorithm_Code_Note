#include<iostream>
#include<algorithm>
#include<memory.h>
#include<vector>
#include<string>
#include<map>
#include<list>
#include<queue>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#pragma warning(disable: 4996)
#define f(n) for(long long int i=0;i<n;i++)
#define p(a) cout<<a<<endl;
#define pb push_back
using namespace std;

priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int> >, greater<pair<long long int, long long int> > > PQ; // 오름차순 정렬


// 최단경로 알고리즘 : 그래프의 두 정점 연결하는 최단 길이 찾는 문제
// 1. 음수 간선의 중요성 : 음수 사이클 유의
// 2. 단일 시작점과 모든 쌍 알고리즘
// 3. 방향 그래프와 무방향 그래프

// 다익스트라 알고리즘
// 1. 우선순위 큐를 사용하는 BFS : 다익스트라 알고리즘에서는 우선순위 큐에 정점의 번호와함께
// 지금까지 찾아낸 해당 정점까지의 최단거리를 쌍으로 넣는다. 우선순위 큐는 정점까지의 최단거리를
// 기준으로 정점을 배열함으로써, 아직 방문하지 않은 정점 중 시작점으로부터의 거리가 
// 가장 가까운 점을 찾는 과정을 간단하게 해준다.
// 2. BFS와 공통점
// - 각 정점까지의 최단거리를 저장하는 배열 dist[]를 유지
// - 정점을 방문시 인접 정점 모두 검사
// - 간선(u,v)를 검사했는데 v가 만약 아직 방문하지 않은 정점이라면
// - u까지의 최단거리에(u,v)의 가중치를 더해 v까지의 경로의 길이를 찾는다.
// - 이것이 지금까지 우리가 찾은 최단거리라면 dist[v]를 갱신하고 (dist[v],v)를 큐에 넣는다.
// 3. 유의점 : 최단경로가 갱신될 수 있다는 사실
// 4. 구현 : 
// - 우선순위 큐 내의 (12,c)를 찾아(9,c)로 바꾼다.
// - (12,c)를 그대로 두고 (9,c)를 추가한 뒤 나중에 (12,c)가 나오면 무시
// -> 주로 사용, dist[u]<cost라면 무시

// 벨만-포드의 최단 경로 알고리즘
// 1. 다익스트라의 한계 : 음수간선이 있을 때 정당성을 보장하지 못한다.
// 2. 요약 : 시작점에서 각 정점까지 가는 최단거리의 상한을 적당히 예측한 뒤 예측 값과 실제 최단거리사이의 오차를 반복적으로 줄여가는 방식으로 동작
// -> 최단거리의 상한을 담은 배열 upper[]유지
// 3. 동작 과정
// - upper[s] = 0으로 초기화하고 나머지 INF로 초기화
// - 시작점에서 u와v까지의 최단거리 dist[u], dist[v]에 대해 dist[v] <= dist[u] + w(u,v)
// - 이러한 방식으로 upper[x]를 줄여가기
// - 모든 간선에 대해 완화(|V|-1번 완화) : 최단 경로나온다.


// 다익스트라 구현

// 최대 정점 개수와 INF값
const long long int MAX_V = 20001;
const long long int INF = 987654321;

// 정점의 개수
long long int V;

// 그래프의 인접 리스트(연결된 정점 번호, 간선 가중치) 쌍을 담는다
vector<pair<long long int, long long int> > adj[MAX_V];

// 다익스트라 구현 : 시작점을 인수로 받는다
vector<long long int> dijkstra(long long int src)
{
	// 정점 개수만큼 INF값 저장하기 : 정점별로 시작점으로부터의 거리
	vector<long long int> dist(V, INF);
	dist[src] = 0;
	priority_queue<pair<long long int, long long int> >pq;
	pq.push(make_pair(0, src));
	while (!pq.empty())
	{
		long long int cost = -pq.top().first;
		long long int here = pq.top().second;
		pq.pop();

		// 만약 지금 꺼낸 것보다 더 짧은 경로를 알고 있다면 지금 꺼낸 것을 무시한다
		if (dist[here] < cost) continue;

		// 인접한 정점들을 모두 검사한다
		for (long long int i = 0; i < adj[here].size(); i++)
		{
			long long int there = adj[here][i].first;
			long long int nextDist = cost + adj[here][i].second;

			// 더 짧은 경로를 발견하면, dist[]를 갱신하고 우선순위 큐에 넣는다
			if (dist[there] > nextDist)
			{
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
	return dist;

}

int main()
{
	
	long long int e;
	//cin >> V >> e;
	scanf("%lld %lld", &V, &e);

	long long int s;
	scanf("%lld",&s);

	long long int u, v, w;
	f(e)
	{
		//cin >> u >> v >> w;
		scanf("%lld %lld %lld", &u, &v, &w);
		adj[u-1].push_back(make_pair(v-1,w));
		//p(u << v << w);

	}
	vector<long long int> ans = dijkstra(s-1);

	f(V)
	{
		if (ans[i] == INF)
		{
			printf("INF\n");
		}
		else
			printf("%lld\n", ans[i]);
	}

	return 0;
}

