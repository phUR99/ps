#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
#define ll long long
ll n, m, k;

int main()
{
    fastio;
    cin >> n >> m >> k;
    vector<ll> arr(n), cmp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cmp[i] = arr[i];
        k -= arr[i];
    }
    sort(cmp.begin(), cmp.end());
    ll now = cmp[n - m];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - now > k)
        {
            cout << -1 << ' ';
            continue;
        }
        }

    return 0;
}
