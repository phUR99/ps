#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
void solve();
int k;
const int d = 1e9 + 7;
long long cache[100005];
long long pSum[100005];
/*
dp + 누적합
*/

int main()
{
    fastio;
    int t;
    cin >> t >> k;
    fill(cache, cache + k, 1);
    for (int i = k; i <= 100000; i++)
    {
        cache[i] = cache[i - 1] + cache[i - k];
        cache[i] %= d;
    }
    for (int i = 1; i <= 100000; i++)
    {
        pSum[i] = pSum[i - 1] + cache[i];
    }

    while (t--)
    {
        int l, r;
        cin >> l >> r;
        cout << (pSum[r] - pSum[l - 1]) % d << '\n';
    }

    return 0;
}
