#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;
bool visited[200005];
vector<vector<int>> adj;
int answer = 0;
const int NEEDED = 0;
const int UNNEED = 1;
const int STITCH = 2;
/*
1. 리프 노드는 붙이지 않는다
2. 자식 노드를 결정하고 부모 노드를 결정한다.
3. 자식 노드 중 붙여지지 않은 노드가 있다면 붙인다.
4. 자식 노드 중 붙여지지 않은 노드가 있다면 붙이지 않는다.
*/

int dfs(int here)
{
    visited[here] = true;
    vector<int> state(3, 0);
    for (int there : adj[here])
    {
        if (visited[there])
            continue;
        state[dfs(there)]++;
    }
    if (state[NEEDED])
    {
        answer++;
        return STITCH;
    }
    if (state[STITCH])
        return UNNEED;
    return NEEDED;
}

int main()
{
    fastio;
    cin >> n >> m;
    adj.resize(n + 1);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i] && dfs(i) == NEEDED)
            answer++;
    }
    cout << answer;
    return 0;
}