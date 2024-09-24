#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
int t;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int answer = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= k)
            answer += arr[i];
        if (arr[i] == 0)
        {
            if (answer == 0)
                continue;
            cnt++;
            answer -= 1;
        }
    }
    cout << cnt << '\n';
}

int main()
{
    fastio;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
