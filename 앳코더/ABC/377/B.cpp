#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

void solve()
{
    vector<vector<char>> board(8, vector<char>(8));
    vector<vector<bool>> visit(8, vector<bool>(8, false));
    for (auto &i : board)
    {
        for (auto &j : i)
        {
            cin >> j;
        }
    }
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] != '#')
                continue;
            visit[i][j] = true;
            for (int dir = 0; dir < 4; dir++)
            {
                int x = i;
                int y = j;
                while (true)
                {
                    x += dx[dir];
                    y += dy[dir];
                    if (x < 0 || x >= 8 || y < 0 || y >= 8)
                        break;
                    if (board[x][y] == '#')
                        break;
                    visit[x][y] = true;
                }
            }
        }
    }
    int ret = 0;
    for (auto i : visit)
    {
        for (auto j : i)
        {
            ret += (!j);
        }
    }
    cout << ret << '\n';
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