#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)

bool search(string cur)
{
    cout << "? " << cur << endl;
    int ret;
    cin >> ret;
    return ret;
}

void solve()
{
    int n;
    cin >> n;
    string cur("");
    while (cur.size() < n)
    {
        if (search(cur + "0"))
            cur += "0";
        else if (search(cur + "1"))
            cur += "1";
        else
            break;
    }
    while (cur.size() < n)
    {
        if (search("0" + cur))
            cur = "0" + cur;
        else
            cur = "1" + cur;
    }
    cout << "! " << cur << endl;
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