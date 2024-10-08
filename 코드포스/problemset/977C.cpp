#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (auto &i : arr)
    {
        cin >> i;
    }
    sort(arr.begin(), arr.end());
    if (k == 0 && arr[0] != 1)
    {
        cout << 1;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        int num = upper_bound(arr.begin(), arr.end(), arr[i]) - arr.begin();
        if (num == k)
        {
            cout << arr[i] << '\n';
            return;
        }
    }
    cout << "-1\n";
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
