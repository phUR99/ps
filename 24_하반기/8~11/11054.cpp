#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
int arr[1005];
int n;
int cache1[1005], cache2[1005];

int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        cache1[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] >= arr[i])
                continue;
            cache1[i] = max(cache1[i], cache1[j] + 1);
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        cache2[i] = 1;
        for (int j = n - 1; j > i; j--)
        {
            if (arr[j] >= arr[i])
                continue;
            cache2[i] = max(cache2[i], cache2[j] + 1);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(cache1[i] + cache2[i] - 1, ans);
    }
    cout << ans;

    return 0;
}
