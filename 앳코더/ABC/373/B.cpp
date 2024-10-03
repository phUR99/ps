#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)

int main()
{
    fastio;
    string str;
    cin >> str;
    int cur = str.find('A');
    int ans = 0;
    for (char i = 'B'; i <= 'Z'; i++)
    {
        int nxt = str.find(i);
        ans += abs(nxt - cur);
        cur = nxt;
    }
    cout << ans << '\n';
    return 0;
}
