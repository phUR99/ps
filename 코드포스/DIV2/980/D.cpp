#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
/*
1. 그래프로 모델링
i와 i-1의 간선과, i와 b를 연결하는 간선으로 구성된 방향 그래프 구성
2. 간선의 가중치?
가중치를 얻는 방식(최장 경로)가 아니라 가중치를 빼는 방식(최단 경로)로 설계
가중치가 있는 그래프에서의 최단 경로이므로 다익스트라로 설계 가능
-->
문제의 목표를 내가 직접 구할지, 아니면 전체에서 안되는 부분을 빼서 구할지를 고민해보기

*/
void solve()
{
    int n;
    cin >> n;
    vector<ll> dist(n + 1, 1e18), pSum(n + 1, 0), arr(n + 1);
    vector<vector<pair<ll, ll>>> adj(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pSum[i] = pSum[i - 1] + arr[i];
        adj[i].push_back({0, i - 1});
    }
    for (int i = 1; i <= n; i++)
    {
        int b;
        cin >> b;
        adj[i].push_back({arr[i], b});
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        ll d = cur.first;
        ll e = cur.second;
        if (d > dist[e])
            continue;
        for (auto nxt : adj[e])
        {
            ll nd = nxt.first;
            ll ne = nxt.second;
            if (dist[ne] > nd + d)
            {
                dist[ne] = nd + d;
                pq.push({dist[ne], ne});
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++)
    {
        ans = max(ans, pSum[i] - dist[i]);
    }
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
