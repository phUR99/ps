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
    map<int, long long> cnt;
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        cnt[tmp - i]++;
    }
    long long ans = 0;
    for (auto iter : cnt)
    {
        ans += iter.second * (iter.second - 1) / 2;
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
