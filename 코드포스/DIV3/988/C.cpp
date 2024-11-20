#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
void solve()
{
    int n;
    cin >> n;
    if (n < 5)
    {
        cout << -1 << '\n';
    }
    else
    {
        for (int i = 2; i <= n; i += 2)
        {
            if (i != 4)
                cout << i << ' ';
        }
        cout << "4 5 ";
        for (int i = 1; i <= n; i += 2)
        {
            if (i != 5)
                cout << i << ' ';
        }
        cout << '\n';
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