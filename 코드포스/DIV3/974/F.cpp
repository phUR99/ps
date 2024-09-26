#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)

int arr[200005];
long long cache[200005][2];

vector<vector<int>> adj;
bool visited[200005];
void dfs(int cur, int c)
{
    visited[cur] = true;
    cache[cur][0] = 0;
    cache[cur][1] = arr[cur];
    vector<int> child;

    for (int nxt : adj[cur])
    {
        if (visited[nxt])
            continue;
        dfs(nxt, c);
        cache[cur][0] += max(cache[nxt][0], cache[nxt][1]);
        cache[cur][1] += max(cache[nxt][0], cache[nxt][1] - 2 * c);
        child.push_back(nxt);
    }
}

void solve()
{
    int n, c;
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    memset(cache, -1, sizeof(cache));
    memset(visited, 0, sizeof(visited));
    adj.clear();
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, c);
    cout << max(cache[1][0], cache[1][1]) << '\n';
}

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
