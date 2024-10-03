#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int M = 0;
    int s1 = 0, s2 = 0;
    for (int i = 0; i < n; i += 2)
    {
        s1++;
        M = max(a[i], M);
    }
    s1 += M;
    M = 0;
    for (int i = 1; i < n; i += 2)
    {
        s2++;
        M = max(a[i], M);
    }
    s2 += M;
    cout << max(s1, s2) << '\n';
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
