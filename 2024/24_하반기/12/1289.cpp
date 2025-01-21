#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
/*
1.
cache[i][0] : i를 루트로 할 때 i를 끝점으로 하지 않는 가중치의 합
cache[i][1] : i를 루트로 할 때 i를 끝점으로 하거나, i를 포함하는 가중치의 합
cache[here][0] = cache[there][0] + cache[there][1]
cache[here][1] = cache[there][1] * (1+cost) + 서브트리의 조합
서브트리의 조합을 빠르게 구하기 위해서 테크닉
서브트리의 합을 S라 할 때
S2 * S1 + S3 *(S2+S1)...의 형태로 O(N)에 해결할 수 있음(오버플로 조심하기)
*/
int n;
vector<vector<pair<int, int>>> adj;
ll cache[100005][2];
const ll MOD = 1e9 + 7;
void dfs(int here, int parent)
{
    ll sum = 0;
    for (auto nxt : adj[here])
    {
        int cost = nxt.first;
        int there = nxt.second;
        if (there == parent)
            continue;
        dfs(there, here);
        cache[here][0] += cache[there][0] + cache[there][1];
        cache[here][0] %= MOD;
        cache[here][1] += (cache[there][1] + 1LL) * (ll)cost;
        cache[here][1] %= MOD;
    }

    for (auto nxt : adj[here])
    {

        int cost = nxt.first;
        int there = nxt.second;
        if (there == parent)
            continue;
        ll value = (sum % MOD * (cache[there][1] + 1LL) % MOD) * (ll)cost % MOD;
        sum += (cache[there][1] + 1LL) * (ll)cost;
        sum %= MOD;
        cache[here][0] += value;
        cache[here][0] %= MOD;
    }
    // cout << "HERE: " << here << ' ' << cache[here][0] << ' ' << cache[here][1] << '\n';
}

int main()
{
    fastio;
    cin >> n;
    adj.resize(n + 1);
    memset(cache, 0, sizeof(cache));
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    dfs(1, -1);
    cout << (cache[1][0] + cache[1][1]) % (MOD);
    return 0;
}