#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)

void solve()
{
    int n, d;
    cin >> n >> d;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end());
    int m[100005], s[100005];
    long long pSum[100005];
    memset(pSum, 0, sizeof(pSum));
    for (int i = 0; i < n; i++)
    {
        m[i] = arr[i].first;
        s[i] = arr[i].second;
    }
    int l = 0, r = 0;
    long long ans = 0, cur = 0;
    /*
    이 포맷이 좀더 깔끔한듯
    */
    for (int r = 0; r < n; r++)
    {
        cur += s[r];
        while (l < n && m[r] - m[l] >= d)
        {
            cur -= s[l];
            l++;
        }
        ans = max(ans, cur);
    }
    cout << ans;
}

int main()
{
    fastio;
    solve();
    return 0;
}
