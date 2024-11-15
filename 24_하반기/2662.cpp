#include <bits/stdc++.h>
using namespace std;
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
int N, M;
int costs[305][25];
int cache[305][25];
int trace[305][25];
/*
어떻게 추적하지?
1. remain - i 로 연속해서 추적하기

*/
int maxProfit(int idx, int remain)
{
    if (idx == M)
        return 0;
    int &ret = cache[remain][idx];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int i = 0; i <= N; i++)
    {
        if (remain >= i)
        {
            if (ret < maxProfit(idx + 1, remain - i) + costs[i][idx])
            {
                ret = maxProfit(idx + 1, remain - i) + costs[i][idx];
                trace[remain][idx] = remain - i;
            }
        }
    }
    return ret;
}

int main()
{
    fastio;
    cin >> N >> M;
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < N; i++)
    {
        int cost;
        cin >> cost;
        for (int j = 0; j < M; j++)
        {
            cin >> costs[cost][j];
        }
    }
    int ret = maxProfit(0, N);
    cout << ret << '\n';
    int cur = N;
    for (int i = 0; i < M; i++)
    {
        cout << cur - trace[cur][i] << ' ';
        cur = trace[cur][i];
    }

    return 0;
}