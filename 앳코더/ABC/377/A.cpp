#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

void solve()
{
    string str;
    cin >> str;
    sort(str.begin(), str.end());
    if (str[0] == 'A' && str[1] == 'B' && str[2] == 'C')
        cout << "Yes\n";
    else
        cout << "No\n";
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