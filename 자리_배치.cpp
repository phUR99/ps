#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int cache[45][45];
int fibo[45];

void precalc()
{
    fibo[0] = 1;
    fibo[1] = 1;
    for (int i = 2; i <= 40; i++)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
}

int n, m;

int main()
{
    fastio;
    memset(cache, 0, sizeof(cache));
    precalc();
    cin >> n >> m;
    int ret = 0;
    cache[0][0] = 1;
    int l = m - 1;
    int r = n - m;
    ret = 0;
    for (int i = 0; i < l; i++)
    {
        if (i == l - 1)
            ret += fibo[r] * fibo[i] * fibo[l - i - 1];
        else
            ret += fibo[r] * fibo[i] * fibo[l - i - 1] * 2;
    }
    for (int i = 0; i < r; i++)
    {
        if (i == r - 1)
            ret += fibo[l] * fibo[i] * fibo[r - i - 1];
        else
            ret += fibo[l] * fibo[i] * fibo[r - i - 1] * 2;
    }
    cout << ret;

    return 0;
}