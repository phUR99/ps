#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
void solve();
/*


*/
void solve()
{
    long long n, a, b;
    cin >> n >> a >> b;
    long long cur = 1;
    set<long long> board;
    while (cur <= n)
    {
        if (board.count(cur % b))
            break;
        if (cur % b == n % b)
        {
            cout << "Yes\n";
            return;
        }
        board.insert(cur % b);
        cur *= a;
    }
    cout << "No\n";
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
