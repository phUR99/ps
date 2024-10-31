#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
/*
1. 구간에 대한 대답을 해야하는 경우에는 한쪽 끝을 어떻게 잡을지에 대해서 생각해보기
*/
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> d(m + 1, 1);
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        d[r] = max(d[r], l + 1);
    }
    for (int i = 1; i <= m; i++)
    {
        d[i] = max(d[i], d[i - 1]);
    }
    long long ret = 0;
    for (int i = 1; i <= m; i++)
    {
        ret += i - d[i] + 1;
    }
    cout << ret << '\n';
}

int main()
{
    fastio;
    int t;
    t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}