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
    long long st = max(1, n - k + 1);
    long long ed = n;
    long long s1, s2;
    s1 = st * (st - 1) / 2;
    s2 = ed * (ed + 1) / 2;

    if ((s2 - s1) % 2 == 0)
        cout << "yes\n";
    else
        cout << "no\n";
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
