#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
// 1. 무향 그래프에서의 사이클 판정
// DFS
/*
모든 방문하지 않은 정점에 대해서 DFS를 수행하면서 사이클 판정 시도
부모 정점을 제외하고 방문했던 지점에 도달했을 경우 역방향 간선의 존재 -> 사이클
*/
vector<bool> visited;
bool dfs(int here, int parent)
{
    if (visited[here])
        return true;
    visited[here] = true;
    for (auto there : adj[here])
    {
        if (there != parent && dfs(there, here))
            return true;
    }
    return false;
}
// union-find
/*
갖고 있는 모든 간선에 대해서 union_find를 실행
특정 간선에 대해서 노드의 부모가 같을 경우 사이클 존재
*/

// 2. 방향 그래프에서의 사이클 판정
/*
역방향 간선이 존재하는지를 찾기
1. 함수 호출이 종료되지 않았는데 방문할 경우 사이클 존재
*/
int counter = 0;
vector<int> discovered;
vector<bool> finished(1000, 1e9);
bool dfs2(int here)
{
    discovered[here] = counter++;
    for (int there : adj[here])
    {
        // 먼저 발견되었으면서 함수 호출이 끝나지 않았다 -> 역방향 간선 판정
        if (discovered[there] < discovered[here] && !finished[there])
            return true;
        // 아직 판정되지 않은 정점에 대해서는 함수 실행
        if (dfs2(there))
            return true;
    }
    // 함수 종료
    finished[here] = true;
    return false;
}