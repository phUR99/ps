#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
void solve()
{
    long long n;
    int s;
    cin >> n >> s;
    long long cnt = 0;
    long long e = 1;
    while (n)
    {

        long long cur = n;
        long long tmp = 0;
        while (cur)
        {
            tmp += cur % 10;
            cur /= 10;
        }
        if (tmp <= s)
        {
            cout << cnt << '\n';
            return;
        }
        int r = n % 10LL;
        cnt += e;
        if (r == 9)
        {
            e *= 10;
            n /= 10;
         }
        n++;
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
