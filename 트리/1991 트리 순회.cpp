#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<ctime>
#include<string>
#include<queue>
#include<memory.h>
#include<map>
#pragma warning(disable: 4996)
#define p(a) cout<<a<<endl
#define f(n) for(int i=0;i<n;i++)
#define pb push_back
using namespace std;


// 인접 리스트 
vector<string> tree[100001];
map<string, pair<string,string> > Tree;
int arr[26];

string MAP[26] = { "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z" };

void pre(int root)
{
	// 방문 표시
	arr[root] = 1;

	cout << MAP[root];
	// 앞부분 먼저
	if (Tree[MAP[root]].first != ".")
	{
		f(26)
		{
			//p(Tree[MAP[root]].first << MAP[i]);
			if (MAP[i] == Tree[MAP[root]].first && arr[i] == 0)
			{
				
				pre(i);
				break;
			}
		}
	}


	if (Tree[MAP[root]].second != ".")
	{
		f(26)
		{
			if (MAP[i] == Tree[MAP[root]].second && arr[i] == 0)
			{
				//if (i == 6)
				//	cout <<'\n'<< root<<MAP[root]<< Tree[MAP[root]].second << endl;
				//if (i == 6)
				//	cout << Tree[MAP[root]].second << endl;
				pre(i);
				break;
			}
		}

	}



}
void mid(int root)
{
	// 방문 표시
	arr[root] = 1;

	
	// 앞부분 먼저
	if (Tree[MAP[root]].first != ".")
	{
		f(26)
		{
			//p(Tree[MAP[root]].first << MAP[i]);
			if (MAP[i] == Tree[MAP[root]].first && arr[i] == 0)
			{
				mid(i);
				break;
			}
		}
	}
	cout << MAP[root];
	if (Tree[MAP[root]].second != ".")
	{
		f(26)
		{
			if (MAP[i] == Tree[MAP[root]].second && arr[i] == 0)
			{
				mid(i);
				break;
			}
		}

	}



}
void post(int root)
{
	// 방문 표시
	arr[root] = 1;

	
	// 앞부분 먼저
	if (Tree[MAP[root]].first != ".")
	{
		f(26)
		{
			//p(Tree[MAP[root]].first << MAP[i]);
			if (MAP[i] == Tree[MAP[root]].first && arr[i] == 0)
			{
				post(i);
				break;
			}
		}
	}
	
	if (Tree[MAP[root]].second != ".")
	{
		f(26)
		{
			if (MAP[i] == Tree[MAP[root]].second && arr[i] == 0)
			{
				post(i);
				break;
			}
		}

	}
	cout << MAP[root];


}

//int mid()
//{
//
//
//}
//
//int post()
//{
//
//
//
//}
int v;
int main()
{
	
	memset(arr, 0, sizeof(arr));


	// 2 <= 트리 정점의 개수 받기 <= 26 
	cin >> v;


	// 간선의 정보 입력받기 : 정점번호, 정점까지의 거리 - 마직막에는 -1 입력받기
	// 1 <= 주어지는 거리 <= 10000
	string spotNum, right, left;
	f(v)
	{
		//연결된 정점 입력
		cin >> spotNum>>left>>right;

		for(int j=0;j<26;j++)
		{
			if(MAP[j]==spotNum)
				// 연결정보 저장하기
				Tree[MAP[j]] = make_pair(left, right);
		}
		
		//cout <<'\n'<<"안녕"<< spotNum << left << right<<endl;

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

	pre(0);
	memset(arr, 0, sizeof(arr));
	p("");
	mid(0);
	memset(arr, 0, sizeof(arr));
	p("");
	post(0);




	return 0;
}
