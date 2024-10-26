#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

void solve()
{
    int a, b;
    cin >> a >> b;
    if (a >= b)
    {
        cout << a << '\n';
    }
    else if (a * 2 <= b)
    {
        cout << 0 << '\n';
    }
    else
    {
        cout << 2 * a - b << '\n';
    }
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
