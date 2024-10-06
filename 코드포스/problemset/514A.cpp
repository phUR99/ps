#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
void solve()
{
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        int now = str[i] - '0';
        if (i == 0 && now == 9)
            continue;
        if (now >= 5)
            str[i] = 9 - now + '0';
    }

    cout << str;
}

int main()
{
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
