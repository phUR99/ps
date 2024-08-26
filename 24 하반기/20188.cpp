#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)

#define ll long long
using namespace std;
vector<vector<int>> adj;
ll n;
ll answer = 0;
bool visited[300005];
/*

답이 경로의 개수의 합을 출력하는 것이므로 정점이 아닌 간선에 집중
(앞으로는 문제의 출력에 대해서 생각해보자, 출력이 정점의 조합이 아니라, 간선의 개수의 합이었으므로
정점보다 간선에 집중했으면 생각했을 수 있었음.)
-> 두 개의 정점에 대해서 특정한 간선을 몇 번 지나갈 수 있는가?
1. 두 정점이 모두 특정 경로에 대해서 자식의 형태
2. 한 정점은 자식의 형태, 다른 정점은 반대편(1 쪽)에 있을때
3. 모두 반대 -> 나오지 않는 경우의 수
1, 2,에 대해서 자식의 정점을 세준 후 조합으로 풀어낸다.
*/
ll dfs(int cur)
{
    visited[cur] = true;
    ll ret = 1;
    for (auto nxt : adj[cur])
    {
        if (visited[nxt])
            continue;
        ll k = dfs(nxt);
        answer += (n - k) * k + k * (k - 1) / 2;
        ret += k;
    }
    return ret;
}

int main()
{
    fastio;
    cin >> n;
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    cout << answer;
    return 0;
}