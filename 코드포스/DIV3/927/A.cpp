#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

void solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    str += "..";
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '.')
            continue;
        if (str[i] == '@')
            ans++;
        if (str[i] == '*' && str[i + 1] == '*')
            break;
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
