#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    if (n == 1 || n == 2)
    {
        cout << "-1\n";
        return;
    }
    long long l = 0;
    long long r = 1e12;
    while (l <= r)
    {
        long long mid = (l + r) / 2;
        double average = (double)(sum + mid) / n;
        average /= 2;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < average)
                cnt++;
        }
        if (cnt > n / 2)
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << l << '\n';
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
