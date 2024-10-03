#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)

int main()
{
    fastio;
    int ans = 0;
    for (int i = 1; i <= 12; i++)
    {
        string str;
        cin >> str;
        ans += (str.size() == i);
    }
    cout << ans << '\n';

    return 0;
}
