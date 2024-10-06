#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
/*
1. 그리디(투 포인터)
2. DP

*/
void solve()
{
    int n, m;
    vector<int> g, b;
    cin >> n;
    g.resize(n);
    for (auto &i : g)
    {
        cin >> i;
    }
    cin >> m;
    b.resize(m);
    for (auto &i : b)
    {
        cin >> i;
    }
    sort(g.begin(), g.end());
    sort(b.begin(), b.end());
    int gp = 0, bp = 0;
    int answer = 0;
    while (gp < n && bp < m)
    {
        if (abs(g[gp] - b[bp]) <= 1)
        {
            answer++;
            gp++;
            bp++;
        }
        else
        {
            if (g[gp] > b[bp])
                bp++;
            else
                gp++;
        }
    }
    cout << answer;
}
void solve2()
{
    int n, m;
    vector<int> g, b;
    cin >> n;
    g.resize(n);
    for (auto &i : g)
    {
        cin >> i;
    }
    cin >> m;
    b.resize(m);
    for (auto &i : b)
    {
        cin >> i;
    }
    sort(g.begin(), g.end());
    sort(b.begin(), b.end());
    vector<vector<int>> cache(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (abs(g[i - 1] - b[j - 1]) <= 1)
                // 두 사람을 짝지을 수 있을때
                cache[i][j] = cache[i - 1][j - 1] + 1;
            // 한 사람을 제외하고 지은 짝의 최댓값
            cache[i][j] = max({cache[i][j - 1], cache[i - 1][j], cache[i][j]});
        }
    }
    cout << cache[n][m];
}

int main()
{
    fastio;
    int t = 1;
    while (t--)
    {
        solve2();
    }

    return 0;
}
