#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
const int upper = 1e9 + 100;
int bino[205][205];
void calcBino()
{
    memset(bino, 0, sizeof(bino));
    for (int i = 0; i <= 200; i++)
    {
        bino[i][0] = bino[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            bino[i][j] = min(upper, bino[i - 1][j - 1] + bino[i - 1][j]);
        }
    }
}
int n, m, k;

string solve(int n, int m, int k)
{
    if (n == 0)
        return string(m, 'z');
    if (m == 0)
        return string(n, 'a');
    if (k < bino[n + m - 1][n - 1])
        return "a" + solve(n - 1, m, k);

    return "z" + solve(n, m - 1, k - bino[n + m - 1][n]);
}
int main()
{
    fastio;
    calcBino();
    cin >> n >> m >> k;
    k--;
    if (bino[n + m][n] <= k)
    {
        cout << -1 << '\n';
        return 0;
    }

    string ret = solve(n, m, k);
    cout << ret;
    return 0;
}