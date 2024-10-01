#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
void solve();
/*
문제 이해를 잘못했음
*/
void solve()
{
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    long long diff = 0;
    for (int i = 1; i < n; i++)
    {
        diff = max(-arr[i] + arr[i - 1], diff);
        arr[i] += max(-arr[i] + arr[i - 1], 0LL);
    }
    int cnt = 0;
    while (diff)
    {
        diff >>= 1;
        cnt++;
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
