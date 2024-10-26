#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

void solve()
{
    long long n, k;
    cin >> n >> k;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }
    long long cur = 0, cnt = 0;
    int now = 0;
    while (true)
    {
        cur += (long long)(pq.top() - now) * (long long)pq.size();
        if (cur >= k)
            break;
        now = pq.top();
        pq.pop();
        cnt++;
    }
    cout << cnt + k << '\n';
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
