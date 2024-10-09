#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
/*
1. 전체 합이 x로 나누어 떨어지지 않으면 그대로 쓰면 됨
2. 전체 합이 x로 나누어 떨어지면 최장 길이 부분수열 을 구해야함
i번째 원소까지 더했을 때 x로 나누어 떨어지지 않는다면
-> 지금까지 더해온 왼쪽과 앞으로 더할 오른쪽을 비교해서 더 큰 길이를 가져가면 됨
-> 이 가정이 확실하지 않으므로 부분합으로 변경
*/

void solve()
{
    int n, x;
    cin >> n >> x;

    vector<int> pSum(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int cur;
        cin >> cur;
        pSum[i] = pSum[i - 1] + cur;
    }
    int ans = -1;
    for (int i = 0; i <= n; i++)
    {
        int l = pSum[i];
        int r = pSum[n] - pSum[i];
        if (l % x)
            ans = max(ans, i);
        if (r % x)
            ans = max(ans, n - i);
    }
    cout << ans << '\n';
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
