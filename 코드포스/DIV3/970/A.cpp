#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
/*
합이 동일한 두 배열로 나눌수 있는가?
*/
void solve()
{
    int a;
    int b;
    cin >> a >> b;
    if (a % 2 != 0)
    {
        cout << "NO\n";
        return;
    }
    if (b % 2 == 0)
    {
        cout << "YES\n";
        return;
    }
    if (a == 0)
    {
        cout << "NO\n";
    }
    else
        cout << "YES\n";
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
