#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)

void solve()
{
    int n;
    cin >> n;
    if (n < 4)
    {
        cout << "-1\n";
        return;
    }
    for (int i = n; i >= 1; i--)
    {
        if (i % 2 == 1)
            cout << i << ' ';
    }
    cout << "4 2 ";
    for (int i = 6; i <= n; i++)
    {
        if (i % 2 == 0)
            cout << i << ' ';
    }
    cout << '\n';
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
