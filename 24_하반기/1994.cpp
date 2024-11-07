#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long

int arr[2005];
map<int, int> cache[2005];
int n;

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int ret = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int diff = arr[j] - arr[i];
            if (cache[i].find(diff) != cache[i].end())
                cache[j][diff] = cache[i][diff] + 1;
            else
                cache[j][diff] = 2;

            ret = max(ret, cache[j][diff]);
        }
    }
    cout << ret << '\n';
}

int main()
{
    fastio;
    int t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}