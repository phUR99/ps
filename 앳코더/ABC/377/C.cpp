#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

void solve()
{
    set<pair<int, int>> s;
    long long n;
    int m;
    cin >> n >> m;
    int dx[] = {0, 2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        for (int i = 0; i < 9; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > n)
                continue;
            s.insert({nx, ny});
        }
    }
    long long ret = n * n;
    cout << ret - s.size() << '\n';
}

int main()
{
    fastio;
    int t;
    t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}