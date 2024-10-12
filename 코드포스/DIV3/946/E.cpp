#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
/*

오버플로 조심 -> 50개밖에 안되서 별 생각 안했는데 50 *1e8 50억임
1. 냅색문제
행복 지수가 50000까지 밖에 안되므로
cache의 인덱스를 hi로 잡을생각하기
*/
void solve()
{

    long long m, x;
    cin >> m >> x;

    vector<int> cost(m), happ(m);
    for (int i = 0; i < m; i++)
    {
        cin >> cost[i] >> happ[i];
    }
    int M = accumulate(happ.begin(), happ.end(), 0);

    vector<long long> cache(M + 1, 1e18);
    cache[0] = 0;
    for (long long i = 0; i < m; i++)
    {
        for (int j = M; j >= happ[i]; j--)
        {
            if (cache[j - happ[i]] + cost[i] <= (long long)x * i)
                cache[j] = min(cache[j], cache[j - happ[i]] + cost[i]);
        }
    }
    for (int i = M; i >= 0; i--)
    {
        if (cache[i] != 1e18)
        {
            cout << i << '\n';
            break;
        }
    }
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
