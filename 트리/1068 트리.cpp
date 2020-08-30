#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
 
#define NODENUM 52
 
using namespace std;
 
typedef struct _TREE_
{
    int val;
    int parent;
    vector<int> child;
 
}TREE;
 
queue<int> q;
TREE tree[NODENUM];
 
int cnt;
 
void bfs(int start)
{
    q.push(start);
 
    while (!q.empty())
    {
        int here = q.front();
        q.pop();
        
        // 리프 노드이면
        if (tree[here].child.empty())
            cnt++;
 
        for (int i = 0; i < tree[here].child.size(); i++)
            q.push(tree[here].child[i]);
    }
}
 
int main()
{
    int n, start;
 
    scanf("%d", &n);
 
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tree[i].val);
 
        if (tree[i].val == -1)
        {
            start = i;
            continue;
        }
 
        else
        {
            int par = tree[i].val; // 부모
            int chi = i; // 자식
 
            tree[chi].parent = par;
            tree[par].child.push_back(chi);
        }
 
    }
 
    int del;
 
    scanf("%d", &del);
    
    // 예외적으로 루트 노드가 지워질 대상이면
    if (del == start)
    {
        printf("0");
        return 0;
    }
 
    // 해당하는 노드의 자식을 모두 지운다.
    tree[del].child.clear();
 
    // 해당하는 노드를 벡터에서 지운다.
    int par = tree[del].parent;
 
    for (int i = 0; i < tree[par].child.size(); i++)
    {
        if (tree[par].child[i] == del)
            tree[par].child.erase(tree[par].child.begin() + i);
    }
        
    bfs(start);
    
    printf("%d", cnt);
 
    return 0;
}
