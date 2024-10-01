#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
void solve();
vector<vector<int>> adj;
vector<int> visited, cat;
int n, m;
/*
연속적인 조건을 까먹었음 + 리프 노드 도달 가능성만 체크하는 문제
*/
int dfs(int cur, int cnt)
{
    if (cnt > m)
        return 0;
    visited[cur] = true;
    int ret = 0;
    bool isLeaf = true;
    for (int nxt : adj[cur])
    {
        if (visited[nxt])
            continue;
        isLeaf = false;
        ret += dfs(nxt, (cat[nxt] == 0 ? 0 : 1 + cnt));
    }
    if (isLeaf)
        return 1;
    return ret;
}

void solve()
{

    adj.clear();
    visited.clear();
    cat.clear();
    cin >> n >> m;
    adj.resize(n + 1);
    cat.resize(n + 1);
    visited.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> cat[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ret = dfs(1, cat[1]);
    cout << ret << '\n';
}

int main()
{
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
