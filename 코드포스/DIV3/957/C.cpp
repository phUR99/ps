#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    priority_queue<int> l, g;
    deque<int> dq;
    for (int i = 1; i <= m; i++)
    {
        g.push(-i);
    }
    for (int i = m + 1; i < k; i++)
    {
        dq.push_back(i);
    }
    for (int i = k; i <= n; i++)
    {
        l.push(-i);
    }
    while (!l.empty())
    {
        auto cur = -l.top();
        l.pop();
        dq.push_front(cur);
    }
    while (!g.empty())
    {
        auto cur = -g.top();
        g.pop();
        dq.push_back(cur);
    }
    for (auto &i : dq)
    {
        cout << i << ' ';
    }
    cout << '\n';
}

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
