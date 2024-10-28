#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

void solve()
{
    int n, c, d;
    cin >> n >> c >> d;
    map<int, int> arr;
    for (int i = 0; i < n * n; i++)
    {
        int e;
        cin >> e;
        arr[e]++;
    }
    int p = arr.begin()->first;
    for (int i = 0; i < n; i++)
    {
        int now = p + c * i;
        for (int j = 0; j < n; j++)
        {
            int cur = now + d * j;
            if (arr[cur] == 0)
            {
                cout << "NO\n";
                return;
            }
            arr[cur]--;
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
