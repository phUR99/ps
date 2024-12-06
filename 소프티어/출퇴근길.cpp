#include <bits/stdc++.h>
using namespace std;
/*
1. 처음에는 두개를 각각 방문한 배열 중에서 둘 다 true인 원소만 더해주는 방식으로 함
1 -> 3 <- 2 라는 반례 생성
s에서 x로 도달 가능하고 x에서 s로 도달 가능성을 어떻게 찾을까라는 고민
----> 정방향 간선과 역방향 간선 2개를 만들어서 DFS를 수행
정방향 간선 -> S에서 도달 가능?
역방향 간선 -> S로 도달 가능?
정방향 간선과 역방향 간선의 이해가 필요할듯

주의점 !!
S -> T -> X를 막기 위해서 S에서 탐색할 때는 T를 방문처리, T에서 탐색할 때는 S를 방문처리해야한다
*/
bool visited1[100005];
bool visited2[100005];
bool visited3[100005];
bool visited4[100005];
vector<vector<int>> adj, r_adj;
int n, m;
void dfs(int here, bool visit[], vector<vector<int>> &arr)
{
    visit[here] = true;
    for (int there : arr[here])
    {
        if (!visit[there])
            dfs(there, visit, arr);
    }
}

void solve(int s, int t)
{
    visited2[s] = true;
    visited1[t] = true;
    dfs(s, visited1, adj);
    dfs(s, visited3, r_adj);
    dfs(t, visited2, adj);
    dfs(t, visited4, r_adj);
    int ret = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visited1[i] && visited2[i] && visited3[i] && visited4[i])
        {
            ret++;
        }
    }
    cout << ret - 2;
}
int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    adj.resize(n + 1);
    r_adj.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        r_adj[b].push_back(a);
    }
    int s, t;
    cin >> s >> t;
    solve(s, t);

    return 0;
}