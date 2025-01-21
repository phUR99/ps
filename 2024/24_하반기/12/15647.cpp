#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
vector<vector<pair<int, int>>> adj;
/*
관찰 1.
사실 합은 어디서나 비슷함: 모든 노드에서의 합을 요구하기 때문에
한 정점과 부모를 연결하는 간선의 입장에서 봤을 때 그 간선을 지나가야만 하는 숫자는
전체 정점에서 그 정점을 루트로 하는 서브트리를 제외한 값
*/
int sub[300005];
ll sum[300005];
int n;

int dfs(int here)
{
    int &ret = sub[here];
    if (ret != -1)
        return ret;
    ret = 1;
    for (auto nxt : adj[here])
    {
        ll cost = nxt.first;
        int there = nxt.second;
        if (sub[there] == -1)
        {
            ret += dfs(there);
            sum[1] += 1LL * cost * sub[there];
        }
    }
    // cout << here << ' ' << ret << '\n';
    return ret;
}
void solve(int here, int parent, ll w)
{
    sum[here] = w;
    // cout << here << ' ' << w << '\n';
    for (auto nxt : adj[here])
    {
        ll cost = nxt.first;
        int there = nxt.second;
        if (there == parent)
            continue;

        ll newW = w + 1LL * cost * (n - 2 * sub[there]);
        solve(there, here, newW);
    }
}

int main()
{
    fastio;
    cin >> n;
    adj.resize(n + 1);
    memset(sub, -1, sizeof(sub));
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    dfs(1);
    solve(1, -1, sum[1]);
    for (int i = 1; i <= n; i++)
    {
        cout << sum[i] << '\n';
    }

    return 0;
}