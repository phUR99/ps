#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
int t;
int n;
int arr[200005];

int main()
{
    fastio;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long sum = 0;
        for (int i = 0; i < n - 2; i++)
        {
            sum += arr[i];
        }
        cout << sum - arr[n - 2] + arr[n - 1] << '\n';
    }

    return 0;
}