#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
#define ll long long
int n;
/*
아이디어
-> 구간 내 홀수는 단 한번만 등장한다
홀수로 존재하는 정수 m이라 할 때 m 미만은 항상 짝수, m 이상은 항상 홀수
-> 따라서 홀수로 존재할 수 있는 정수의 최솟값 or 짝수로 존재할 수 있는 정수의 최댓값 결정 (최적화 문제)
-> 결정 문제로 바꿔서 매개변수 탐색으로 해결
*/
void solve()
{
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(3));
    ll l, r;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    l = 1;
    r = (1 << 31) - 1;
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int a = arr[i][0];
        int c = arr[i][1];
        int b = arr[i][2];
        cnt += (c - a) / b + 1;
    }
    if (cnt % 2 == 0)
    {
        cout << "NOTHING";
        return;
    }
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        ll cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int a = arr[i][0];
            int c = arr[i][1];
            int b = arr[i][2];
            if (a > mid)
                continue;
            cnt += (min(mid, (ll)c) - a) / b + 1;
        }
        if (cnt % 2 == 0)
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << l << ' ';
    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int a = arr[i][0];
        int c = arr[i][1];
        int b = arr[i][2];
        if (a > l || l > c)
            continue;
        cnt += (((int)l - a) % b == 0);
    }
    cout << cnt;
}

int main()
{
    fastio;
    solve();

    return 0;
}
