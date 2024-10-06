#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
void solve()
{
    vector<int> arr(3);
    for (auto &i : arr)
    {
        cin >> i;
    }
    for (int i = 0; i < 5; i++)
    {
        sort(arr.begin(), arr.end());
        arr[0]++;
    }
    cout << arr[0] * arr[1] * arr[2] << '\n';
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
