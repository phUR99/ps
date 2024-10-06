#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
void solve()
{
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (auto &i : arr)
    {
        cin >> i;
    }
    int r = 0;
    long long answer = 0;
    for (int l = 0; l < n;)
    {
        long long M = -1e9 - 12;
        while (r < n && arr[r] * arr[l] > 0)
        {
            M = max(arr[r], M);
            r++;
        }
        l = r;
        answer += M;
    }
    cout << answer << '\n';
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
