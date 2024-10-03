#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
#define ll long long
void solve()
{

    int n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    map<ll, ll> cnt;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (ll i = 0; i < n; i++)
    {
        ll now = (i + 1) * (n - i) - 1;
        cnt[now]++;
        if (i > 0)
        {
            ll tmp = (n - i) * i;
            cnt[tmp] += arr[i] - arr[i - 1] - 1;
        }
    }
    while (q--)
    {
        ll k;
        cin >> k;
        if (cnt.find(k) == cnt.end())
            cout << 0 << ' ';
        else
            cout << cnt[k] << ' ';
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
