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
    string str;
    cin >> str;
    vector<int> alpha(26, -1);
    string dict(str);
    sort(dict.begin(), dict.end());
    dict.erase(unique(dict.begin(), dict.end()), dict.end());

    int len = dict.length();
    map<char, int> num;
    for (int i = 0; i < len; i++)
    {
        num[dict[i]] = i;
    }

    for (int i = 0; i < n; i++)
    {
        char now = str[i];
        int cnt = num[now];
        cout << dict[len - 1 - cnt];
    }
    cout << '\n';
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
