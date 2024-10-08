#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] != '.')
                continue;
            queue<pair<int, int>> q;
            q.push({i, j});
            board[i][j] = 'B';
            while (!q.empty())
            {
                auto cur = q.front();
                q.pop();
                int x = cur.first;
                int y = cur.second;
                char c = board[x][y];
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;
                    if (board[nx][ny] != '.')
                        continue;
                    if (c == 'B')
                        board[nx][ny] = 'W';
                    else
                        board[nx][ny] = 'B';
                    q.push({nx, ny});
                }
            }
        }
    }
    for (auto &i : board)
    {
        for (auto &j : i)
        {
            cout << j;
        }
        cout << '\n';
    }
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
