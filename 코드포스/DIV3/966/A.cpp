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
    if (str.size() < 3)
    {
        cout << "NO\n";
        return;
    }
    int down = 0, exp = 0;
    down = stoi(str.substr(0, 2));
    exp = stoi(str.substr(2));
    if (down != 10 || str[2] - '0' == 0)
    {
        cout << "NO\n";
        return;
    }
    if (exp >= 2)
    {
        cout << "YES\n";
    }
    else
        cout << "NO\n";
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
