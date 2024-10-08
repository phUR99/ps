#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
void solve()
{
    int n, k;
    int odd = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        odd += tmp % 2;
    }
    int even = n - odd;
    if (n == k && odd % 2 != 1)
    {
        cout << "NO\n";
        return;
    }
    if (even != 0 && odd != 0)
    {
        cout << "YES\n";
        return;
    }
    if (even == 0 && k % 2 == 1)
    {
        cout << "YES\n";
        return;
    }
    cout << "No\n";
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
