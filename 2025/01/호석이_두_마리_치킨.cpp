#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;
vector<vector<int>> adj;
int bfs(int s1, int s2)
{
    queue<int> q;
    vector<int> dist(n + 1, -1);
    q.push(s1);
    q.push(s2);
    dist[s1] = 0;
    dist[s2] = 0;
    while (!q.empty())
    {
        int here = q.front();
        q.pop();
        for (auto there : adj[here])
        {
            if (dist[there] == -1)
            {
                q.push(there);
                dist[there] = dist[here] + 1;
            }
        }
    }
    return accumulate(dist.begin(), dist.end(), -dist[0]) * 2;
}

int main()
{
    fastio;
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int s1, s2;
    int dist = 987654321;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int current_dist = bfs(i, j);
            if (current_dist < dist)
            {
                dist = current_dist;
                s1 = i;
                s2 = j;
            }
        }
    }
    cout << s1 << ' ' << s2 << ' ' << dist;
    return 0;
}