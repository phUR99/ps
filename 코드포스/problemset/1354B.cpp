#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)

int find(vector<int> &idx)
{
    int l = 987654321;
    int r = -987654321;
    for (int i = 1; i <= 3; i++)
    {
        if (idx[i] == -1)
            return 987654321;
        r = max(r, idx[i]);
        l = min(l, idx[i]);
    }
    return r - l + 1;
}
void solve()
{
    vector<int> idx(4, -1);
    string str;
    cin >> str;
    int ans = 987654321;
    for (int i = 0; i < str.size(); i++)
    {
        int n = str[i] - '0';
        idx[n] = i;
        ans = min(ans, find(idx));
    }
    if (ans == 987654321)
        cout << "0\n";
    else
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
