#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
/*
로그 -> 부동소수점..
곱해서 -> 오버플로우
구해야 하는 b를 미리 i로 나눈 다음에 구하기..

*/
const int MX = 1e7;
bool isPrime[MX + 5];
void precalc()
{
    fill(isPrime, isPrime + MX + 5, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i <= MX; i++)
    {
        if (isPrime[i] == 1)
        {
            for (int j = i * i; j <= MX; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }
}

int main()
{
    fastio;
    precalc();
    ll a, b;
    cin >> a >> b;
    int ret = 0;
    for (ll i = 2; i * i <= b; i++)
    {
        if (!isPrime[i])
            continue;
        ll val = i;
        while (val <= b / i)
        {
            val *= i;
            if (val >= a)
                ret++;
        }
    }
    cout << ret;
    return 0;
}