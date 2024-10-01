#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
/*
1. 항상 왼쪽으로 넘기는 것이 오른쪽으로 넘기거나 넘기지 않는 것보다는 나쁘지 않을 상황을 만듦.
2. 오른쪽으로 넘기는 것이 넘기지 않는 것보다는 나쁘지 않을 상황을 만듦.
-> 왼쪽으로 넘길 수 있다면 왼쪽으로 넘기고, 이후 오른쪽으로 넘길 수 있다면
오른쪽으로 넘긴 후에 새로운 경계를 반영해준다.
-> 항상 최선의 결과임이 보장됨 ->그리디

*/
void solve()
{
    int n;
    cin >> n;
    int x[100005], h[100005];
    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        cin >> h[i];
    }
    x[n] = 1e10;
    for (int i = 1; i < n; i++)
    {
        if (x[i] - h[i] > x[i - 1])
        {
            cnt++;
            continue;
        }
        if (x[i] + h[i] < x[i + 1])
        {
            cnt++;
            x[i] += h[i];
            continue;
        }
    }
    cout << cnt;
}

int main()
{
    fastio;
    solve();
    return 0;
}
