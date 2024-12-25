#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
/*
탐욕적 선택 증명 : 가장 위의 열부터 연결 가능성을 조사한다.
-> 아닌 해가 있다 가정(가장 위의 열부터 선택한 것이 아닌 그보다 아래의 행을 선택했다 가정)
-> 더 위의 열을 선택했을 때 선택지가 많아진다.(선의 교차 가능성이 줄기 때문에)
따라서 가장 위의 열을 선택했을 때 손해를 보지 않는다.
최적 부분 구조 : 가장 위의 열을 선택했을 때 다음 선택은 그 밑의 열의 연결 가능성을 탐색하는 것이 유리
*/
int n, m;
char board[10005][705];
bool visited[10005][705];
int dx[] = {-1, 0, 1};
int dy[] = {1, 1, 1};
int dfs(int x, int y)
{
    if (y == m)
        return 1;
    int ret = 0;
    // cout << x << ' ' << y << '\n';
    visited[x][y] = 1;
    for (int dir = 0; dir < 3; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny > m)
            continue;
        if (visited[nx][ny] || board[nx][ny] == 'x')
            continue;
        if (dfs(nx, ny))
        {
            return 1;
        }
    }
    // 현재 상태에서 탐색에 실패했다면 다시 볼 필요는 없다(어차피 다음 상태에서도 불가능)
    // 되던 안되던 파이프는 회수할 필요가 없음
    // visited[x][y] = 0;
    return 0;
}

int main()
{
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        ret += dfs(i, 0);
    }

    cout << ret;
    return 0;
}