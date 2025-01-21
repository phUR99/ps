#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
int p[15];
/*
1. 000000의 처리
최대한 큰 자리 숫자를 만든 다음에 첫번째 자리부터 교체 가능한지를 체크하는 방식으로 설계했는데
000000같은 경우에서 문제 발생
->첫번째 자리는 반드시 0을 제외한 다른거로
불가능한 경우는 예외 처리로

*/
void solve()
{
    int n, m;
    cin >> n;
    int minCost = 987654321;
    int minIdx = -1;

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        if (minCost >= p[i])
        {
            minCost = p[i];
            minIdx = i;
        }
    }
    int minCostA = 987654321;
    int minIdxA = -1;
    for (int i = 1; i < n; i++)
    {
        if (minCostA >= p[i])
        {
            minCostA = p[i];
            minIdxA = i;
        }
    }
    cin >> m;

    if (minCostA > m)
    {
        cout << 0 << '\n';
        return;
    }
    string ret = to_string(minIdxA);
    m -= minCostA;
    while (m >= minCost)
    {
        m -= minCost;
        ret += to_string(minIdx);
    }

    for (int i = 0; i < ret.size(); i++)
    {
        for (int j = n - 1; j > ret[i] - '0'; j--)
        {
            if (p[j] - p[ret[i] - '0'] <= m)
            {
                m -= p[j] - p[ret[i] - '0'];
                ret[i] = j + '0';
                break;
            }
        }
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