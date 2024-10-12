#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
/*
1. 그리디하게 생각했을 때..
현재 가능한 제한이 존재하고 이 제한 안에서 가장 많은 원소를 들고 있게 하는게 목표
가능한 최대로 원소를 들고 있다가 제한을 넘기면 버리는 식으로 짜자.

*/
void solve()
{
    int m, x;
    cin >> m >> x;
    int ans = 0;
    priority_queue<int> pq;
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        int limit = x * i;
        int cur;
        cin >> cur;
        pq.push(cur);
        sum += cur;
        while (sum > x * i)
        {
            sum -= pq.top();
            pq.pop();
        }
        ans = max((int)pq.size(), ans);
    }
    cout << ans << '\n';
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
