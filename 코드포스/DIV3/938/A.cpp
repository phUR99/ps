#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    if (a * 2 <= b)
    {
        cout << n * a << '\n';
    }
    else
    {
        cout << n / 2 * b + a * (n % 2) << '\n';
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
