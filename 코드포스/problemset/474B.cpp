#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
void solve()
{
    int n, m;
    vector<int> arr = {0};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr.push_back(arr.back() + num);
    }
    arr.push_back(1e6 + 1);
    cin >> m;
    while (m--)
    {
        int q;
        cin >> q;
        int idx = lower_bound(arr.begin(), arr.end(), q) - arr.begin();
        cout << idx << '\n';
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
