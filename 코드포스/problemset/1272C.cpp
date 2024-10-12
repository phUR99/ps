#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)

void solve()
{
    int n, k;
    vector<int> dict(26, 0);
    cin >> n >> k;
    string str;
    cin >> str;
    for (int i = 0; i < k; i++)
    {
        char c;
        cin >> c;
        dict[c - 'a']++;
    }
    long long ans = 0;
    long long cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (dict[str[i] - 'a'])
        {
            cnt++;
        }
        else
        {
            ans += cnt * (cnt + 1) / 2;
            cnt = 0;
        }
    }
    ans += cnt * (cnt + 1) / 2;
    cout << ans << '\n';
}

int main()
{
    fastio;
    int t;
    t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}
