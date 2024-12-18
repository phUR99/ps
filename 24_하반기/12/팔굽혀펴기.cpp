#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
/*
1. n까지 만든 합의 턴의 수를 k라 할 때
a * k + a * k-1...의 형식이 성립(k는 조건상 최대 100)
solve(sum, turn) 현재 합이 sum이고, turn번째 순서 일 때 최대가 되는 점수의 합
*/
int arr[15];
int cache[5005][105];
int n, m;
int caching(int sum, int turn)
{
    if (sum == 0)
        return 0;
    int &ret = cache[sum][turn];
    if (ret != -1)
        return ret;
    ret = -987654321;
    for (int i = 0; i < m; i++)
    {
        if (sum - turn * arr[i] >= 0)
            ret = max(ret, caching(sum - turn * arr[i], turn + 1) + arr[i]);
    }
    return ret;
}
void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }

    memset(cache, -1, sizeof(cache));
    int ret = caching(n, 1);
    if (ret < 0)
        ret = -1;
    cout << ret << '\n';
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