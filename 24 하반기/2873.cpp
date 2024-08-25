#include <bits/stdc++.h>
using namespace std;

#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
int dist[1005][1005];
int arr[1005][1005];
bool visited[1005][1005];
int N, M;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
string word = "ULDR";

int solve(int x, int y)
{
    if (x < 0 || x >= N || y < 0 || y >= M)
        return -987654321;
    if (visited[x][y])
        return -987654321;

    if (x == N - 1 && y == M - 1)
        return arr[N - 1][M - 1];
    int &ret = dist[x][y];
    if (ret != -1)
        return ret;
    ret = 0;
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        ret = max(ret, solve(x + dx[i], y + dy[i]) + arr[x][y]);
    }
    visited[x][y] = false;
    return ret;
}
void solution(int x, int y)
{

    if (x == N - 1 && y == M - 1)
        return;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;
        if (dist[x][y] == dist[nx][ny] + arr[x][y] || (nx == N - 1 && ny == M - 1))
        {
            cout << word[i];
            solution(nx, ny);
            return;
        }
    }
}

int main()
{
    fastio;
    memset(dist, -1, sizeof(dist));
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
    int answer = solve(0, 0);

    solution(0, 0);

    return 0;
}