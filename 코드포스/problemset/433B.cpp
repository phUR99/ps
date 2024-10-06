#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
void solve()
{
    int n, q;

    cin >> n;
    vector<int> arr(n);
    vector<long long> pSum(n + 1, 0), sPsum(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        pSum[i] = pSum[i - 1] + arr[i - 1];
    }
    sort(arr.begin(), arr.end());
    for (int i = 1; i <= n; i++)
    {
        sPsum[i] = sPsum[i - 1] + arr[i - 1];
    }
    cin >> q;
    while (q--)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1)
        {
            cout << pSum[r] - pSum[l - 1] << '\n';
        }
        else
        {
            cout << sPsum[r] - sPsum[l - 1] << '\n';
        }
    }
}

int main()
{
    fastio;
    int t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}
