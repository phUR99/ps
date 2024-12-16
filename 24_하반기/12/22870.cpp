#include <bits/stdc++.h>
using namespace std;
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
#define ll long long
/*
A -> B 최단거리를 기록하고 B 노드에서 다시 거슬러 올라가며 최단거리를 탐색할 때
1. 노드 번호가 작은 노드로 거슬러 올라가며 탐색한다.

의 경우에는 최단거리가 1 2 3 4 5 6 과 1 3 6 과 같이 주어졌을 경우 오류가 발생합니다.
-> 여기서 틀렸음
2. 노드 번호가 큰 노드로 거슬러 올라가며 탐색한다.

의 경우에는 최단거리가 1 2 6 과 1 5 6 과 같이 주어졌을 경우 오류가 발생합니다.
이는 최단 거리의 직전 노드를 기록할 때
다음 노드의 관점에서 가장 작은 노드 번호를 기록하기 때문에 발생하는 문제

다음 노드의 관점에서 가장 작은 노드 번호를 기록하는게 문제라면
A -> B 의 최단거리를 찾을 때 첫 탐색을 B -> A 의 방향으로 반전시켜 탐색

1. 모든 엣지는 양방향이므로 최단 거리는 변하지 않습니다.
2. B -> A 탐색 후 A 노드에서 거슬러 올라가며 A  -> B 최단 거리를 탐색하면
A -> B 의 관점에서는 현재 노드의 기준으로 직전 노드가 기록되어 있으므로
한 번의 탐색으로 조건을 만족하는 경로를 찾을 수 있습니다.
*/

int N, M;
vector<pair<int, int>> adj[200005];
int dist[200005];
bool del[200005];
int A, B;

void trace(int here)
{
    if (here == B)
        return;
    for (auto nxt : adj[here])
    {
        int there = nxt.first;
        int cost = nxt.second;
        if (dist[here] == dist[there] + cost)
        {
            del[there] = true;
            trace(there);
            return;
        }
    }
}

int dijkstra(int s, int e)
{
    memset(dist, 0x3f, sizeof(dist));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    dist[s] = 0;
    while (!pq.empty())
    {

        auto cur = pq.top();
        pq.pop();
        if (cur.first > dist[cur.second])
            continue;
        for (auto nxt : adj[cur.second])
        {
            if (nxt.second + cur.first < dist[nxt.first] && !del[nxt.first])
            {
                dist[nxt.first] = nxt.second + cur.first;
                pq.push({dist[nxt.first], nxt.first});
            }
        }
    }
    return dist[e];
}

int main()
{
    fastio;
    cin >> N >> M;
    int u, v, c;

    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    cin >> A >> B;
    for (int i = 1; i <= N; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }
    int e2s = dijkstra(B, A);
    trace(A);
    del[B] = 0;
    /*
    for (int i = 1; i <= N; i++)
    {
        cout << "i: " << i << ' ' << del[i] << '\n';
    }
    */
    int s2e = dijkstra(A, B);
    cout << s2e + e2s;
    return 0;
}