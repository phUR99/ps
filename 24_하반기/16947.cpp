#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
/*
1. 사이클 판정
-> 한 점에서 DFS를 시작했을 때 다시 자신으로 돌아올 수 있는가?
무방향 그래프여서 생긴 문제 -> 시작하자마자 다시 자신으로 들어오는 경우
제거용으로 함수 파라미터에 이전 탐색 지점을 추가
2. 주의할 점
-> 사이클 판정 성공시 반환으로 참값의 기록
-> 값 반환 시에 return으로 바로 반환하는 것이 아니라 OR 연산으로 묶어줘야 함(하나만 보고 넘어가면 안되므로)
3. 이후 BFS
사이클이 아닌 지점에서 N번 BFS를 실행해도 되지만
사이클인 지점에서부터 BFS를 시작하면 BFS 한번으로 탐색을 완료할 수 있음
*/
vector<vector<int>> adj;
int n;

bool visited[3005];
bool isCycle[3005];
int dist[3005];

bool dfs(int here, int prev, int start)
{
    visited[here] = true;
    for (int there : adj[here])
    {
        if (there == prev)
            continue;
        if (there == start)
            return isCycle[here] = true;
        if (!visited[there])
        {
            isCycle[here] |= dfs(there, here, start);
        }
    }
    return isCycle[here];
}

int main()
{
    fastio;
    cin >> n;
    adj.resize(n + 1);
    memset(dist, -1, sizeof(dist));
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        memset(visited, 0, sizeof(visited));
        if (dfs(i, -1, i))
            break;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (isCycle[i])
        {
            q.push(i);
            dist[i] = 0;
        }
    }
    while (!q.empty())
    {
        int here = q.front();
        q.pop();
        for (int there : adj[here])
        {
            if (dist[there] == -1)
            {
                dist[there] = dist[here] + 1;
                q.push(there);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << ' ';
    }

    return 0;
}