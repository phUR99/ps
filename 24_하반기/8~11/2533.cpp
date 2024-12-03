#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;
vector<vector<int>> adj;
bool visited[1000005];
int answer = 0;
const int need = 0;
const int unneed = 1;
/*
1. 얼리어답터가 아니면 반드시 친구는 얼리어답터여야함
2. dfs로 해결
맨 밑 노드부터 해결
2-1. 리프노드는 항상 선택하지 않는 것이 유리함
루트 노드는 자식 노드 중에서 얼리어답터가 아닌 노드가 있으면 반드시 선택해야함
*/

int solve(int here)
{
    visited[here] = true;
    vector<int> status(2, 0);
    for (auto there : adj[here])
    {
        if (visited[there])
            continue;
        ++status[solve(there)];
    }
    if (status[need])
    {
        answer++;
        return unneed;
    }
    return need;
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
    solve(1);
    cout << answer << '\n';

    return 0;
}