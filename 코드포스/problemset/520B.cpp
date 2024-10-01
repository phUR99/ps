#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> dist(10005, -1);
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        int nxt = cur * 2;
        if (nxt <= 10000 && dist[nxt] == -1)
        {
            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
        nxt = cur - 1;
        if (nxt >= 0 && dist[nxt] == -1)
        {
            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }
    cout << dist[m];
}

int main()
{
    fastio;
    solve();
    return 0;
}
