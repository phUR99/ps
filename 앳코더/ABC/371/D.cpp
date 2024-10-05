#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
#define ll long long

ll pSum[200005];
ll arr[200005];

int main()
{
    fastio;
    int n, q;
    cin >> n;
    arr[0] = -1e9 - 12;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        pSum[i] = tmp + pSum[i - 1];
    }
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l = lower_bound(arr, arr + n + 1, l) - arr;
        r = upper_bound(arr, arr + n + 1, r) - arr;

        cout << pSum[r - 1] - pSum[l - 1] << '\n';
    }

    return 0;
}
