#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
/*
1. 위상정렬 + DP
-> 정방향으로 위상정렬을 하되 DP를 이용해서 상태를 저장
2. 역뱡향 위상정렬
-> 역방향으로 간선을 만들어준 뒤 indegree = 0 위상정렬
-> 큐에 들어가는 정점의 수(사이클이 생기지 않는 정점의 수)
 */
int cache[100005];
bool visited[100005];
int dfs(int cur, vector<vector<int>> &adj)
{

    int &ret = cache[cur];
    if (ret != -1)
        return ret;
    ret = 1;
    for (auto nxt : adj[cur])
    {
        if (visited[nxt])
            return ret = 0;

        visited[nxt] = true;
        ret &= dfs(nxt, adj);
        visited[nxt] = false;
    }
    return ret;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    memset(cache, -1, sizeof(cache));
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        visited[i] = true;
        answer += dfs(i, adj);
        visited[i] = false;
    }
    cout << answer << '\n';
}

int main()
{
    fastio;
    solve();

    return 0;
}
