#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)

void solve()
{
    vector<int> cnt(51, 0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int idx;
        cin >> idx;
        cnt[idx]++;
    }
    vector<int> ans(101, 0);
    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j <= 50; j++)
        {
            if (i - j > 50 || i < 2 * j)
                continue;
            if (i != 2 * j)
                ans[i] += min(cnt[j], cnt[i - j]);
            else
                ans[i] += cnt[j] / 2;
        }
    }
    cout << *max_element(ans.begin(), ans.end()) << '\n';
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
