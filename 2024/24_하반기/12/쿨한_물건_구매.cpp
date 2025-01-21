#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
/*

Dhat = np + mq 일 때, n을 결정하면 m 역시 결정됨
p의 반복횟수는 d/p + 1번 혹은 q-1번 (q번 이상일 경우 q로 나눈 것과 동치)
이후 tmp-1 ~ tmp+1번까지 확인
*/

int main()
{
    fastio;

    ll d, p, q;
    cin >> d >> p >> q;
    ll ret = 0x3f3f3f3f3f3f3f3f;
    if (p < q)
        swap(p, q);
    for (int i = 0; i < min(q, d / p + 2); i++)
    {
        ll tmp = (d - p * i) / q;
        for (int j = max(0LL, tmp - 2); j < tmp + 2; j++)
        {
            if (p * i + q * j < d)
                continue;
            ret = min(ret, p * i + q * j);
        }
    }
    cout << ret;
    return 0;
}