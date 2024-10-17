#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

void solve()
{
    int n;
    long long ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long long a;
        cin >> a;
        long long d = ans / a + 1;
        ans = a * d;
    }
    cout << ans << '\n';
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
