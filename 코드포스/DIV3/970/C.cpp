#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)

void solve()
{
    int l, r;
    cin >> l >> r;
    int cnt = 0;
    while (cnt * (cnt + 1) / 2 <= r - l)
    {
        cnt++;
    }
    cout << cnt << '\n';
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
