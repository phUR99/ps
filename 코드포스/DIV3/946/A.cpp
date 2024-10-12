#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)

void solve()
{
    int x, y;
    cin >> x >> y;
    cout << max(y / 2 + y % 2, (4 * y + x) / 15 + ((4 * y + x) % 15 != 0)) << '\n';
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
