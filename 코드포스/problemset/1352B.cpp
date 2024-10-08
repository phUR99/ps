#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
void solve()
{
    int n, k;
    cin >> n >> k;
    if (n < k || (n % 2 == 1 && k % 2 == 0))
    {
        cout << "NO\n";
        return;
    }
    if ((n - k) % 2 == 0)
    {
        cout << "YES\n";
        for (int i = 0; i < k - 1; i++)
        {
            cout << "1 ";
        }
        cout << n - k + 1 << '\n';
        return;
    }
    if (n >= 2 * k)
    {
        cout << "YES\n";
        for (int i = 0; i < k - 1; i++)
        {
            cout << 2 << ' ';
        }
        cout << n - 2 * (k - 1) << '\n';
        return;
    }
    cout << "NO\n";
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
