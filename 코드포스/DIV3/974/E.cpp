#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)

#define ll long long
vector<vector<pair<ll, int>>> adj;
bool horse[200005];
const ll inf = 1e18;
ll dist_s[400005], dist_e[400005];
/*
1. dist를 2차원 배열로 선언하면서 dist를 채워나가는 방식 -> 시간 초과 어디선가 반복이 많이 일어난 거 같음
**2. adj의 간선을 2개로 나누기 -> w/2,w로 나눈 후에 horse[i] 해당하는 정점에만 연결하는 방식
->다익스트라 코드를 수정 or 인접 행렬을 적절히 수정하기
1번만 주로 해봤으나 2번도 생각해봐야겠다.

*/

void dijkstra(int st, ll dist[])
{
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, st});
    dist[st] = 0;
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        ll curDist = cur.first;
        ll curEdge = cur.second;
        if (curDist > dist[curEdge])
            continue;
        for (auto nxt : adj[curEdge])
        {
            int nxtEdge = nxt.second;
            ll nxtDist = nxt.first;
            if (dist[nxtEdge] > dist[curEdge] + nxtDist)
            {
                dist[nxtEdge] = dist[curEdge] + nxtDist;
                pq.push({dist[nxtEdge], nxtEdge});
            }
        }
    }
}
void solve()
{
    int n, m, h;
    cin >> n >> m >> h;
    adj.clear();
    adj.resize(2 * n + 1);
    memset(horse, 0, sizeof(horse));
    fill(dist_s, dist_s + 2 * n + 1, inf);
    fill(dist_e, dist_e + 2 * n + 1, inf);

    for (int i = 0; i < h; i++)
    {
        int tmp;
        cin >> tmp;
        horse[tmp] = true;
    }
    //////////////////////////////////////// 핵심
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[u + n].push_back({w / 2, v + n});
        adj[v].push_back({w, u});
        adj[v + n].push_back({w / 2, u + n});
    }
    for (int i = 1; i <= n; i++)
    {
        if (horse[i])
            adj[i].push_back({0, i + n});
    }
    ////////////////////////////////////////
    dijkstra(1, dist_s);
    dijkstra(n, dist_e);
    ll ans = inf;
    for (int i = 1; i <= n; i++)
    {
        ans = min(max(min(dist_e[i], dist_e[i + n]), min(dist_s[i], dist_s[i + n])), ans);
    }
    if (ans >= inf)
        ans = -1;
    cout << ans << '\n';
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
