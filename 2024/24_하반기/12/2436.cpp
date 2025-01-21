#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
/*
1e4 = sqrt(1e8) 감안하면 큰 숫자는 아님(반복 가능)
m를 찢는 방법은 m을 찢은 숫자 a와 b가 서로소여야만 함(gcd(a, b) = 1)

*/

int main()
{
    fastio;
    int gcd, lcm;
    cin >> gcd >> lcm;
    int m = lcm / gcd;
    int x;
    int sum = 987654321;
    for (int i = 1; i * i <= m; i++)
    {
        if (m % i == 0 && (m / i + i) < sum && __gcd(i, (m / i)) == 1)
        {
            x = i;
            sum = (m / i + i);
        }
    }
    cout << x * gcd << ' ' << (m / x) * gcd;

    return 0;
}