#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
void solve()
{
    int n, m;
    cin >> n;
    vector<int> arr(n);
    for (auto &i : arr)
    {
        cin >> i;
    }
    cin >> m;
    map<char, int> cMatching;
    map<int, char> iMatching;

    while (m--)
    {
        string str;
        cin >> str;
        if ((int)str.size() != n)
        {
            cout << "NO\n";
            continue;
        }
        cMatching.clear();
        iMatching.clear();
        bool ans = true;
        for (int i = 0; i < n; i++)
        {
            if (!cMatching.count(str[i]))
                cMatching[str[i]] = arr[i];
            else
                ans &= (cMatching[str[i]] == arr[i]);
            if (!iMatching.count(arr[i]))
                iMatching[arr[i]] = str[i];
            else
                ans &= (iMatching[arr[i]] == str[i]);
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
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
