#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int indexSCC; bool visited[10001]; stack<int> topology;
void topologySort(vector<vector<int>> &adj, int startNode)
{
	visited[startNode] = true;
	for (int i = 0; i < adj[startNode].size(); i++)
		if (!visited[adj[startNode][i]]) topologySort(adj, adj[startNode][i]);
	topology.push(startNode);
}
void Kosaraju(vector<vector<int>> &rev_adj, int startNode, vector<int> &SCC)
{
	visited[startNode] = true;
	SCC.push_back(startNode);
	for (int i = 0; i < rev_adj[startNode].size(); i++)
		if (!visited[rev_adj[startNode][i]]) Kosaraju(rev_adj, rev_adj[startNode][i], SCC);
}
int main()
{
	int N, T, A, B;
	vector<vector<int>> adj, rev_adj, SCC;
	cin >> N >> T;
	adj.resize(N + 1); rev_adj.resize(N + 1);
	while (cin >> A >> B) adj[A].push_back(B), rev_adj[B].push_back(A);
	for (int i = 1; i <= N; i++) if (!visited[i]) topologySort(adj, i);
	memset(visited, 0, sizeof(visited));
	while (!topology.empty())
	{
		int top = topology.top();
		topology.pop();
		if (visited[top]) continue;
		SCC.resize(++indexSCC);
		Kosaraju(rev_adj, top, SCC[indexSCC - 1]);
	}
	cout << indexSCC << '\n';
	for (int i = 0; i < indexSCC; i++) sort(SCC[i].begin(), SCC[i].end());
	sort(SCC.begin(), SCC.end());
	for (int i = 0; i < indexSCC; i++)
	{
		for (int j = 0; j < SCC[i].size(); j++) cout << SCC[i][j] << ' ';
		cout << -1 << '\n';
	}
	return 0;
}
