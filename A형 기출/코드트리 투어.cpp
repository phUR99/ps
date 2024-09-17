#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
vector<vector<pair<int, int>>> adj;
int Q;
int n, m;
int isValid[30005];
int rev[30005];
int dist[2005];
int destination[30005];
/*
쿼리 100000:
200, 300, 400이 30000씩 들어오기 때문에 최적화는 이 셋을 중점으로
500은 15번밖에 안들어오니까 좀 비효율적이라도 예외 케이스가 없는 방식으로..
특정 정점에 대해서 모든 정점의 최단거리를 알아야 하니까 다익스트라로 접근
이후 우선순위 큐를 이용해서 정렬
우선순위 큐를 이용해서 생기는 정렬
-> 큐 안에 있는 원소가 사용 불가능할 경우
A : 큐 안에 id를 집어넣어서 id가 사용 불가능한지를 체크하기
이후 시작점이 바뀔 경우 다익스트라를 다시 실행
*/

int st = 0;
void dijkstra()
{
    fill(dist, dist + n, 987654321);
    dist[st] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, st});
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        int cost = cur.first;
        int dest = cur.second;
        if (dist[dest] < cost)
            continue;
        for (auto nxt : adj[dest])
        {
            int nxtCost = nxt.first;
            int nxtDest = nxt.second;
            if (dist[nxtDest] > nxtCost + dist[dest])
            {
                dist[nxtDest] = nxtCost + dist[dest];
                pq.push({dist[nxtDest], nxtDest});
            }
        }
    }
}
struct node
{
    int cost;
    int id;
    bool operator<(const node &a) const
    {
        if (a.cost == cost)
            return a.id < id; // 내림차순
        return cost < a.cost; // 오름차순
    }
};
priority_queue<node> pq;

int main()
{
    fastio;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int cmd;
        cin >> cmd;
        if (cmd == 100)
        {
            cin >> n >> m;
            adj.resize(n);
            for (int j = 0; j < m; j++)
            {
                int u, v, w;
                cin >> u >> v >> w;
                adj[u].push_back({w, v});
                adj[v].push_back({w, u});
            }
            dijkstra();
        }
        // 30000
        else if (cmd == 200)
        {
            int id, revenue, dest;
            cin >> id >> revenue >> dest;
            isValid[id] = true;
            rev[id] = revenue;
            destination[id] = dest;
            pq.push({revenue - dist[dest], id});
        }
        // 30000
        else if (cmd == 300)
        {
            int id;
            cin >> id;
            isValid[id] = false;
        }
        // 30000
        else if (cmd == 400)
        {
            int ret = -1;
            while (!pq.empty())
            {
                auto cur = pq.top();
                pq.pop();
                int cost = cur.cost;
                int id = cur.id;
                if (!isValid[id] || cost < 0)
                    continue;
                isValid[id] = false;
                ret = id;
                break;
            }
            cout << ret << '\n';
        }
        // 15
        else
        {
            int s;
            cin >> s;
            st = s;
            dijkstra();
            while (!pq.empty())
            {
                pq.pop();
            }
            for (int i = 1; i <= 30000; i++)
            {
                if (isValid[i])
                    pq.push({rev[i] - dist[destination[i]], i});
            }
        }
    }

    return 0;
}