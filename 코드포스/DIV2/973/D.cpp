#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
#define ll long long
int t;

void solve()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll l = -1e15;
    ll r = 1e15;
    ll M = 0;
    ll m = 0;
    while (l <= r)
    {
        vector<ll> cur = arr;
        ll mid = (l + r) / 2LL;
        for (int i = 0; i < n - 1; i++)
        {
            if (cur[i] > mid)
            {
                ll diff = cur[i] - mid;
                cur[i + 1] += diff;
                cur[i] = mid;
            }
        }
        if (cur[n - 1] <= mid)
        {
            M = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    l = -1e15;
    r = 1e15;
    reverse(arr.begin(), arr.end());
    while (l <= r)
    {
        vector<ll> cur = arr;
        ll mid = (l + r) / 2LL;
        for (int i = 0; i < n - 1; i++)
        {
            if (cur[i] < mid)
            {
                ll diff = cur[i] - mid;
                cur[i + 1] += diff;
                cur[i] = mid;
            }
        }
        if (cur[n - 1] >= mid)
        {
            m = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << max(0LL, M - m) << '\n';
}

int main()
{
    fastio;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
