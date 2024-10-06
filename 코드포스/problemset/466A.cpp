#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
void solve()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int ans = 987654321;
    for (int i = 0; i * m <= n + m; i++)
    {
        int cur = m * i;
        ans = min(ans, b * i + max(0, (n - cur)) * a);
    }
    cout << ans;
}

int main()
{
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
