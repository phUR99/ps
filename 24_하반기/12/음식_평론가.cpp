#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
/*
t * (N/M) 이 자연수일 때는 안 잘라도 됨 (t = 1, 2, 3 ... M)
k = gcd(N, M) 이라 할 때
t * (q1 / q2)
M = q2 * k이므로 t가 q2의 배수가 될 수 있는 방법은 총 K가지임
따라서 전체 수에서 k를 뺀 m - gcd(n, k)가 해
*/

int main()
{
    fastio;
    int n, m;
    cin >> n >> m;
    cout << m - __gcd(n, m);
    return 0;
}