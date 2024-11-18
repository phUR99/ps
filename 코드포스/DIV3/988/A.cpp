#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
void solve()
{
    vector<int> cnt(21, 0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int idx;
        cin >> idx;
        cnt[idx]++;
    }
    int ret = 0;
    for (auto i : cnt)
    {
        ret += i / 2;
    }
    cout << ret << '\n';
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