#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
int board[100005];

void solve()
{
    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
    }
    int l = 0;
    int r = 0;
    int sum = 0;
    int cnt = 0;
    int ans = 0;
    while (r < n)
    {
        sum += board[r];
        while (l < n && sum > t)
        {
            sum -= board[l];
            l++;
        }
        ans = max(ans, r - l + 1);
        r++;
    }
    cout << ans;
}

int main()
{
    fastio;
    solve();
    return 0;
}
