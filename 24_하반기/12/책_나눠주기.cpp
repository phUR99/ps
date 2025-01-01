#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
/*
1. 책을 사람 하나에 매칭시키는 문제 -> 이분매칭으로 해결 가능
2. 책의 끝 번호가 낮은 순서대로, 시작 번호가 낮은 순서대로 배정 -> 번호가 낮은 순서대로 배정 -> 그리디
*/
int n, m;
bool matching[1005][1005];
int aMatch[1005], bMatch[1005];
bool visited[1005];
bool dfs(int a)
{
    // 방문 완료시 다시 방문하지 않는다
    if (visited[a])
        return false;
    visited[a] = true;

    for (int b = 1; b <= n; b++)
    {
        if (matching[a][b])
        {
            // b가 매칭되지 않았거나, b를 새롭게 매칭할 수 있다면
            if (bMatch[b] == -1 || dfs(bMatch[b]))
            {
                aMatch[a] = b;
                bMatch[b] = a;
                return true;
            }
        }
    }
    return false;
}

void solve()
{
    cin >> n >> m;
    memset(matching, 0, sizeof(matching));
    memset(aMatch, -1, sizeof(aMatch));
    memset(bMatch, -1, sizeof(bMatch));
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        for (int j = a; j <= b; j++)
        {
            matching[i][j] = 1;
        }
    }
    int ret = 0;
    for (int i = 0; i < m; i++)
    {
        memset(visited, 0, sizeof(visited));
        if (dfs(i))
            ret++;
    }
    cout << ret << '\n';
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