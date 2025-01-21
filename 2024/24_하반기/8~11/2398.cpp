#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
int n, m;
vector<vector<pair<int, int>>> adj;
int dist[1005];
bool visited[1005];
int pre[1005];

int main()
{
    fastio;
    cin >> n >> m;
    adj.resize(n + 1);
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({c, v});
        adj[v].push_back({c, u});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> arr(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> arr[i];
    }
    dist[arr[0]] = 0;
    pq.push({0, arr[0]});
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        if (cur.first > dist[cur.second])
            continue;
        for (auto nxt : adj[cur.second])
        {
            if (dist[nxt.second] > cur.first + nxt.first)
            {
                dist[nxt.second] = cur.first + nxt.first;
                pq.push({dist[nxt.second], nxt.second});
                pre[nxt.second] = cur.second;
            }
        }
    }
    int cnt = 0;
    pre[arr[0]] = -1;
    int cur = 0;
    vector<pair<int, int>> answer;

    for (int i = arr[1]; i != -1; i = pre[i])
    {
        if (cur != 0)
            answer.push_back({i, cur});
        visited[i] = true;
        cur = i;
    }
    cur = 0;
    for (int i = arr[2]; i != -1; i = pre[i])
    {
        if (visited[i])
        {
            cnt = i;
            if (cur != 0)
                answer.push_back({i, cur});
            break;
        }
        if (cur != 0)
            answer.push_back({i, cur});
        cur = i;
    }

    cout << dist[arr[1]] + dist[arr[2]] - dist[cnt] << ' ' << answer.size() << '\n';
    sort(answer.begin(), answer.end());
    for (auto i : answer)
    {
        cout << i.first << ' ' << i.second << '\n';
    }

    return 0;
}