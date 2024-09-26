#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
int pSum[100005];
/*
st 랑 ed를 분리하고 누적합으로 해결하기

*/
void solve()
{
    int n, d, k;
    memset(pSum, 0, sizeof(pSum));
    cin >> n >> d >> k;
    vector<int> st(n + 1, 0), ed(n + 1, 0);
    for (int i = 0; i < k; i++)
    {
        int l, r;
        cin >> l >> r;
        st[l]++;
        ed[r]++;
    }
    for (int i = 1; i <= n; i++)
    {
        st[i] += st[i - 1];
        ed[i] += ed[i - 1];
    }
    int maxDay, minDay;
    int m = 987654321, M = -987654321;
    for (int i = d; i <= n; i++)
    {
        int cur = st[i] - ed[i - d];
        if (cur > M)
        {
            M = cur;
            maxDay = i - d + 1;
        }
        if (cur < m)
        {
            m = cur;
            minDay = i - d + 1;
        }
    }
    cout << maxDay << ' ' << minDay << '\n';
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
