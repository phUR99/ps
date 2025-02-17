#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int cache[505][505];
int n;
string str;

int solve(int l, int r)
{
    if (l >= r)
        return 0;
    int &ret = cache[l][r];
    if (ret != -1)
        return ret;
    if ((str[l] == 'a' && str[r] == 't') || (str[l] == 'g' && str[r] == 'c'))
        ret = solve(l + 1, r - 1) + 2;

    for (int i = l; i <= r; i++)
    {
        ret = max(ret, solve(l, i) + solve(i + 1, r));
    }
    return ret;
}

int main()
{
    fastio;
    cin >> str;
    memset(cache, -1, sizeof(cache));
    n = str.length();
    int ret = solve(0, n - 1);
    cout << ret;
    return 0;
}