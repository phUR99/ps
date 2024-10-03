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
    vector<int> arr(n), visited(n + 2, 0);
    for (auto &i : arr)
    {
        cin >> i;
    }
    for (int i = 0; i < n; i++)
    {
        visited[arr[i]] = 1;
        if (i == 0)
            continue;
        if (!visited[arr[i] - 1] && !visited[arr[i] + 1])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
