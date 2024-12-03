#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
map<ll, ll> prefix;
ll a, b;
/*
2^n-1의 형태에 대해서 누적합을 구해준 후
num을 이 형태의 합으로 만들어준다.
num을 넘지 않는 가장 큰 2의 제곱수로 찢는 형태
*/
ll solve(ll num)
{
    ll ret = 0;
    ll offset = 0;
    while (num)
    {
        ll val = 1;
        while (val <= num)
        {
            val <<= 1;
        }
        val >>= 1;
        ret += prefix[val - 1] + offset * (val);
        num -= val;
        // cout << val << ' ' << num << '\n';
        offset++;
    }

    return ret + offset;
}
/*
0번 비트는 X가 홀수인지 짝수인지 판단
현재 비트가 켜져있을 경우에
켜진 비트의 개수 + 켜진 비트보다 작은 1의 개수의 합
cache[i-1] + x - (1<<i) + 1

ll go(ll x, ll i = 54)
{
    ll ans = x & 1;
    for (; i > 0; i--)
    {
        if (x & (1LL << i))
        {
            ans += d[i - 1] + (x - (1LL << i) + 1);
            x -= 1LL << i;
        }
    }
    return ans;
}
*/
int main()
{
    fastio;
    prefix[0] = 0;
    for (int i = 1; i < 64; i++)
    {
        prefix[(1LL << i) - 1] = 2 * prefix[(1LL << (i - 1)) - 1] + (1LL << (i - 1));
    }
    cin >> a >> b;
    a = solve(a - 1);
    b = solve(b);
    cout << b - a << '\n';
    return 0;
}