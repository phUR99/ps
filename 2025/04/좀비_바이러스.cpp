#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int board[1005][1005];
int rest[1005][1005];
int n, m;
vector<vector<int>> dist;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool oob(int x, int y){
    return x < 0 || x >= n || y < 0 || y >= m;
}

void bfs(vector<vector<int>> &dist){
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(board[i][j] != -1 && board[i][j]){
                q.push({i, j});
                dist[i][j] = 0;
                break;
            }
        }
        
    }
    while (!q.empty())
    {
        auto here = q.front(); q.pop();
        int x = here.first;
        int y = here.second;
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(oob(nx, ny)) continue;
            if(board[nx][ny] == -1) continue;
            if(dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
        
    }
}

int main()
{
    fastio;
    cin >> n >> m;
    dist.resize(n, vector<int>(m, -1));
    return 0;
}