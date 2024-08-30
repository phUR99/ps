#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
#define ll long long

ll dist[100005];
bool visited[100005];
const ll inf = 0x3fffffffffffffff;
ll n, m, c, sum, answer = 0x7fffffffffffffff;
/*
1. 생각을 못했던 부분 -> x 이하의 지점일 때 나머지의 정점이 갈라지는 부분이면 처리를 어떻게 하지? (예제 1)
2. 다익스트라의 논리(그리디하게 방문하는 논리)를 이용해서 사용하지 않을 간선의 처리가 가능하다는 것을 생각하지 못함
3. 모든 간선의 합에서 현재까지 도달한 정점의 간선을 제거하는 방식으로 다익스트라 한번에 처리가 가능함
*/

vector<vector<pair<ll, int>>> adj;
void dijkstra()
{
    fill(dist, dist + n + 1, inf);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0LL, 1});
    dist[1] = 0;
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        if (visited[cur.second])
            continue;
        if (cur.first > dist[cur.second])
            continue;
        // 다익스트라에서 항상 방문의 처리는 큐에 집어넣을 때가 아닌 큐에서 뺄 때임
        visited[cur.second] = true;
        /*
        핵심..
        인접 정점을 체크하면서 이미 도달한 정점인 경우
        (이 경우는 무조건 나보다 거리가 낮음 -> 즉 x 처리를 했을 때 비용이 사라지는 정점임)
        간선의 길이를 고려하지 않아야 하므로 전체 간선 가중치의 합에서 이 값들을 빼줌
        이 처리를 하면서 쓰지 않은 간선의 처리도 동시에 할 수 있음
        */
        for (auto nxt : adj[cur.second])
        {
            if (visited[nxt.second])
                sum -= nxt.first;
        }
        answer = min(answer, c * cur.first + sum);
        for (auto nxt : adj[cur.second])
        {
            if (dist[nxt.second] > nxt.first + cur.first)
            {
                dist[nxt.second] = nxt.first + cur.first;
                pq.push({dist[nxt.second], nxt.second});
            }
        }
    }
}

int main()
{
    fastio;
    cin >> n >> m >> c;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({c, v});
        adj[v].push_back({c, u});
        sum += c;
    }
    dijkstra();
    cout << answer;
    return 0;
}