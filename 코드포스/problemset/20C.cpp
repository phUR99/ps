#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
#define ll long long
ll dist[100005];
int pre[100005];
void solve()
{
    int n, m;
    memset(dist, 0x3f, sizeof(dist));
    memset(pre, -1, sizeof(pre));
    cin >> n >> m;
    vector<vector<pair<ll, int>>> adj;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        ll nowDist = cur.first;
        int nowVertex = cur.second;
        if (dist[nowVertex] > nowDist)
            continue;
        for (auto nxt : adj[nowVertex])
        {
            ll nxtDist = nxt.first;
            int nxtVertex = nxt.second;
            if (dist[nxtVertex] > nxtDist + nowDist)
            {
                dist[nxtVertex] = nxtDist + nowDist;
                pre[nxtVertex] = nowVertex;
                pq.push({dist[nxtVertex], nxtVertex});
            }
        }
    }
    if (pre[n] == -1)
        cout << -1;
    else
    {
        vector<int> ans;
        for (int i = n; i != -1; i = pre[i])
        {
            ans.push_back(i);
        }
        reverse(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << ' ';
        }
    }
}
int main()
{
    fastio;
    solve();

    return 0;
}
