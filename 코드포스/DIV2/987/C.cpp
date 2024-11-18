#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
void solve()
{
    int n;
    cin >> n;
    if (n % 2)
    {
        int idx = -1;
        for (int i = 1; i < n - 1; i++)
        {
            if (sqrt(i) == (int)sqrt(i) && sqrt(n - 1 - i) == int(sqrt(n - 1 - i)) && sqrt(n - 1) == (int)sqrt(n - 1))
            {
                idx = i;
                break;
            }
        }
        if (idx == -1)
        {
            cout << -1 << '\n';
            return;
        }
        vector<int> arr(n, 0);
        arr[0] = arr[idx] = arr[n - 1] = 1;
        int cnt = 2;
        for (int i = 0; i < n; i++)
        {
            if (arr[i])
                continue;
            arr[i] = cnt - cnt % 2;
            cnt++;
        }
        for (auto &i : arr)
        {
            cout << i << ' ';
        }
        cout << '\n';
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cout << (i + 1) / 2 << ' ';
        }
        cout << '\n';
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