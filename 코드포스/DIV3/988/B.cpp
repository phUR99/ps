#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
void solve()
{
    map<int, int> cnt;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int idx;
        cin >> idx;
        cnt[idx]++;
    }
    for (auto iter : cnt)
    {
        int n = iter.first;
        if ((k - 2) % n)
            continue;

        int m = (k - 2) / n;
        if (n == m && cnt[n] < 2)
            continue;
        if (cnt.find(m) == cnt.end())
            continue;
        cout << n << ' ' << m << '\n';
        break;
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