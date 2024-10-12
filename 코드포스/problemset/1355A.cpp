#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
/*
규칙 찾기
-> 그냥은 절대로 불가능(K가 너무 크다)
예제를 손으로 해결해보면서 규칙찾기
--> 결국 최솟값이 0이 되는 지점(곱셈에서 유의미)에서는 다음 항이 모두 같아진다..
*/
void solve()
{
    long long a, k;
    cin >> a >> k;
    k--;
    while (k--)
    {
        long long cur = a;
        long long m = 11;
        long long M = -1;
        while (cur)
        {
            m = min(m, cur % 10);
            M = max(M, cur % 10);
            cur /= 10;
        }
        if (m == 0)
            break;
        a += m * M;
    }
    cout << a << '\n';
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
