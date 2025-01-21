#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
#define MAX 1000 + 5
int counter = 0;         // 노드의 발견 순서 체크
int discovered[MAX];     // 노드의 탐색 여부 체크
set<pair<int, int>> ans; // 노드의 단절선 여부 체크
vector<vector<int>> adj;

int dfs(int node, int parent)
{
    // 현재 노드 탐색 표시
    discovered[node] = counter++;
    int ret = discovered[node];

    for (auto child : adj[node])
    {
        // 역방향 간선 중에 부모로 돌아가는 간선은 제외(현재 사용중임)
        if (child == parent)
            continue;
        if (discovered[child] == -1)
        {
            int subTree = dfs(child, node);
            // 단절점이 아니므로 현재 점에 도달 가능해도 단절선이 될 수 없다
            // 현재의 점보다 반드시 커야 단절선이 가능하다.
            if (subTree > discovered[node])
            {
                pair<int, int> element = (child < node ? make_pair(child, node) : make_pair(node, child));
                ans.insert(element);
            }
            ret = min(ret, subTree);
        }
        else
            ret = min(ret, discovered[child]);
    }
    return ret;
}

void solve()
{
    int v;
    memset(discovered, -1, sizeof(discovered));
    for (int vertex = 1; vertex <= v; vertex++)
    {
        // 탐색하지 않은 모든 정점에 대해서 DFS를 실행한다.
        if (discovered[vertex] == -1)
            dfs(vertex, true);
    }
}

int main()
{
    fastio;

    return 0;
}