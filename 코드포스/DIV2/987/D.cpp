#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
/*
현재 원소보다 왼쪽에 최댓값이 있는 경우 -> 항상 그 최댓값으로 바꿀 수 있음
현재 원소보다 오른쪽에 최솟값이 있는 경우 -> 항상 그 최솟값으로 바꿀수 있음
왼쪽에서의 최댓값 vs 오른쪽에서의 최솟값
왼쪽이 더 클 경우에는 항상 오른쪽에서의 최댓값으로 바꿀 수 있음
오른쪽이 더 크거나 같을 경우에는 왼쪽에서의 최댓값 중에 하나로 반드시 결정해야함

*/

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> ans(n), MX(n), MN(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    MX[0] = arr[0];
    MN[n - 1] = arr[n - 1];
    for (int i = 1; i < n; i++)
    {
        MX[i] = max(MX[i - 1], arr[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        MN[i] = min(MN[i + 1], arr[i]);
    }
    ans[n - 1] = MX[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (MX[i] > MN[i + 1])
            ans[i] = ans[i + 1];
        else
            ans[i] = MX[i];
    }
    for (auto &i : ans)
    {
        cout << i << ' ';
    }
    cout << '\n';
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