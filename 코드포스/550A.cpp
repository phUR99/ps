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
    int n = str.size();
    bool ans = false;
    int idx1 = str.find("AB");
    if (idx1 == -1)
    {
        cout << "NO";
        return;
    }
    int idx2 = str.find("BA", idx1 + 2);
    if (idx2 != -1)
    {
        cout << "YES";
        return;
    }
    idx2 = str.find("BA");
    if (idx2 == -1)
    {
        cout << "NO";
        return;
    }
    idx1 = str.find("AB", idx2 + 2);
    if (idx1 != -1)
    {
        cout << "YES";
    }
    else
        cout << "NO";
}

int main()
{
    fastio;
    solve();
    return 0;
}
