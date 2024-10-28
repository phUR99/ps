#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

void solve()
{
    int n;
    long long k;
    cin >> n >> k;
    deque<long long> dq(n);
    for (int i = 0; i < n; i++)
    {
        cin >> dq[i];
    }
    // dq.size() == 1 일때만 예외처리
    while (dq.size() > 1 && k)
    {
        long long m = min(dq.front(), dq.back());
        if (k < 2 * m)
        {
            dq.front() -= k / 2 + k % 2;
            dq.back() -= k / 2;
            k = 0;
        }
        else
        {
            dq.front() -= m;
            dq.back() -= m;
            k -= 2 * m;
        }
        if (dq.front() == 0)
            dq.pop_front();
        if (dq.back() == 0)
            dq.pop_back();
    }
    int ret = n - dq.size();
    cout << ret + (dq.size() && dq.front() <= k) << '\n';
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
