#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
int t;

int main()
{
    fastio;
    cin >> t;
    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;
        int d = min(x, y);
        cout << n / d + (n % d != 0) << '\n';
    }

    return 0;
}