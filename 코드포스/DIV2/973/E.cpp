#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (n == 1)
    {
        cout << arr.front() << '\n';
        return;
    }

    sort(arr.begin(), arr.end());
    int ret = 0;
    int gcd = arr.front();
    int idx = -1;
    for (int i = 1; i < n; i++)
    {
        if (__gcd(arr.front(), arr[i]) <= gcd)
        {
            gcd = __gcd(arr.front(), arr[i]);
            idx = i;
        }
    }
    swap(arr[1], arr[idx]);
    ret = arr.front();
    for (int i = 1; i < n; i++)
    {
        ret += gcd = __gcd(gcd, arr[i]);
    }
    cout << ret << '\n';
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
