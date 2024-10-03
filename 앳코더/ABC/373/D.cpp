#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
vector<vector<pair<long long, int>>> adj;

long long num[500005];
/*
간선을 거꾸로 넣는 것 까지는 생각했는데..
그래프의 변형에 대해서 고민을 조금
*/

void dfs(int cur)
{
    for (auto nxt : adj[cur])
    {
        long long w = nxt.first;
        int v = nxt.second;
        if (num[v] != 1e18 + 1)
            continue;
        num[v] = num[cur] + w;
        dfs(v);
    }
}

int main()
{
    fastio;
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    fill(num, num + n + 1, 1e18 + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({-w, u});
    }
    for (int i = 1; i <= n; i++)
    {
        if (num[i] != 1e18 + 1)
            continue;
        num[i] = 0;
        dfs(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << num[i] << ' ';
    }

    return 0;
}
