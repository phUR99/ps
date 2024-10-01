#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
/*
1. o(n^2) = 6*e7 -> 1억 이내..
2. 스위핑의 아이디어를 빌려오자..
-> 구간 a ~ b 까지의 연속합을 알 때 필요한건 b ~ n 까지의 원소의 등장 횟수..
1) 원소의 등장횟수를 센 다음에
2) 연속합으로 스위핑하면서 해당하는 등장횟수가 있으면 답에 더해주고 0으로(한번만 세면 끝임)
*/
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), cnt(n + 1);
    for (auto &it : arr)
    {
        cin >> it;
        cnt[it]++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (i == j)
                continue;
            if (sum <= n)
            {
                ans += cnt[sum];
                cnt[sum] = 0;
            }
        }
    }
    cout << ans << endl;
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
