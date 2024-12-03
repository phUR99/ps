#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
/*
n == m일 때의 예외처리(한번밖에 볼 수 없음)
*/
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr(n + m, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (n == m)
    {
        cout << (accumulate(arr.begin(), arr.end(), 0) < k) << '\n';
        return;
    }
    for (int i = n; i < n + m - 1; i++)
    {
        arr[i] = arr[i - n];
    }
    queue<int> q;
    int ret = 0;
    int sum = 0;
    for (int i = 0; i < n + m - 1; i++)
    {
        q.push(arr[i]);
        sum += arr[i];
        if (q.size() == m)
        {
            ret += (sum < k);
            sum -= q.front();
            q.pop();
        }
    }
    cout << ret << '\n';
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