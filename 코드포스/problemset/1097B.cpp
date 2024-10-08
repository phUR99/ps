#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
bool cache[16][360];
int arr[16];
int main()
{
    fastio;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cache[0][arr[0]] = 1;
    cache[0][360 - arr[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int rad = 0; rad < 360; rad++)
        {
            int cur = (arr[i] + rad) % 360;
            cache[i][cur] |= cache[i - 1][rad];
        }
        for (int rad = 0; rad < 360; rad++)
        {
            int cur = (-arr[i] + rad + 360) % 360;
            cache[i][cur] |= cache[i - 1][rad];
        }
    }
    if (cache[n - 1][0])
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
