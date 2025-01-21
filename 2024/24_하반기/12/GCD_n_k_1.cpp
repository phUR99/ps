#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
ll n, ans;
/*
오일러 피 함수 :n이 양의 정수일 때, n과 서로소인 1 부터 n까지의 정수의 개수
오일러 피 함수의 특정 pi(mn) = pi(m) * pi(n)
ex) pi(6) = pi(2) * pi(3)
*/

int main()
{
    fastio;
    cin >> n;
    ans = n;

    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i != 0)
            continue;
        // ans =  ans *(1-1/i);
        // ans =  ans - ans/i;
        ans -= ans / i;
        // i가 없어질 때 까지 i로 나눠준다(i는 이미 구했음)
        while (n % i == 0)
            n /= i;
    }
    // n이 소수일 경우
    if (n > 1)
        ans -= ans / n;
    cout << ans;

    return 0;
}