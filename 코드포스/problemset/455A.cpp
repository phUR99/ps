#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
/*
dp 접근
1. cache[i] : i까지의 최대 점수
-> 점화식 : cache[i] = max(cache[i-1](i를 선택하지 않은 경우),
cache[i-2] + cache[i](i-1을 선택하지 않는 경우))
2.1e5 * 1e5  = 1e10이니 오버플로우를 피하기 위해서 ll 타입으로 배열 만들기
*/

long long cache[100005];
void solve()
{
    int n;
    cin >> n;
    memset(cache, 0, sizeof(cache));
    for (int i = 0; i < n; i++)
    {
        int cur;
        cin >> cur;
        cache[cur] += cur;
    }
    for (int i = 2; i <= 100000; i++)
    {
        cache[i] = max(cache[i - 1], cache[i - 2] + cache[i]);
    }
    cout << *max_element(cache, cache + 100005) << '\n';
}

int main()
{
    fastio;
    solve();
    return 0;
}
