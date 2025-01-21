#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
/*
10만 관찰해도 모든 인수를 파악할 수 있는 이유
10 / 2 = 5 (2, 4, 6, 8, 10) 첫번째 2
10 / 4 = 2 (4, 8)의 두번째 2
10 / 8 = 1 (8)의 3번째 2
인수로 한번씩 스위핑하면서 전부 탐색
*/
int n, m;
int solve(int val, int mod)
{
    int cnt = 0;
    for (ll i = mod; val / i >= 1; i *= mod)
    {
        cnt += val / i;
    }

    return cnt;
}

int main()
{
    fastio;
    cin >> n >> m;
    int two = solve(n, 2) - solve(m, 2) - solve(n - m, 2);
    int five = solve(n, 5) - solve(m, 5) - solve(n - m, 5);
    cout << min(two, five);
    return 0;
}