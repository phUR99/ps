#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
#define ll long long
ll pSum[500005];
int r[500006];
/*
동일한 합을 갖는 세 구간으로 나누기 -> 누적 합으로 접근
1. 가능한 (i, j)의 쌍 찾기 -> L/R 구분해서 찾기
인덱스가 조금 곤란한데 인덱스 주의
*/

void solve()
{
    int n;
    cin >> n;
    memset(r, 0, sizeof(r));
    for (int i = 1; i <= n; i++)
    {
        int cur;
        cin >> cur;
        pSum[i] = pSum[i - 1] + cur;
    }
    if (pSum[n] % 3 != 0)
    {
        cout << 0 << '\n';
        return;
    }
    ll d = pSum[n] / 3;
    int k = 0;
    for (int i = n - 1; i >= 2; i--)
    {
        if (pSum[i] == d * 2)
            k++;
        r[i] = k;
    }
    ll ans = 0;
    for (int i = 1; i <= n - 2; i++)
    {
        if (pSum[i] == d)
            ans += r[i + 1];
    }
    cout << ans << '\n';
}

int main()
{
    fastio;
    solve();
    return 0;
}
