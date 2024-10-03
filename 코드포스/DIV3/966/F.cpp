#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> arr(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
        if (arr[i].first < arr[i].second)
            swap(arr[i].first, arr[i].second);
        sum += arr[i].first + arr[i].second;
    }
    sort(arr.begin(), arr.end());
    if (sum < k)
    {
        cout << -1 << '\n';
        return;
    }
    int cnt = 0;
    int now = 0;
    for (auto &e : arr)
    {

        for (int i = 0; i < e.first; i++)
        {
            for (int j = 0; j < e.second; j++)
            {
                if (now < k)
                {
                    cnt++;
                    if (i == e.first - 1)
                        now++;
                }
            }
            if (now < k)
            {
                now++;
            }
        }
    }
    cout << cnt << '\n';
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
