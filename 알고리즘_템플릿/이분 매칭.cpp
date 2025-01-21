#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long

int n, m;
// A -> B의 연결관계 표시
vector<vector<bool>> adj;
// 각 정점에 매칭된 상대 정점의 번호를 저장한다
vector<int> aMatch, bMatch;
// dfs()의 방문 여부를 체크
vector<bool> visited;
// A의 정점 a에서 B의 매칭되지 않은 정점으로 가는 경로 찾기
bool dfs(int a)
{
    if (visited[a])
        return false;
    visited[a] = true;
    for (int b = 0; b < m; b++)
    {
        if (adj[a][b])
        {
            // b가 이미 매칭되었다면 bMatch[b]부터 시작해서 증가 경로 찾기
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
// 배열을 계산하고 최대 매칭의 크기를 반환
int bipartiteMatch()
{
    aMatch = vector<int>(n, -1);
    bMatch = vector<int>(m, -1);
    int size = 0;
    for (int start = 0; start < n; start++)
    {
        visited = vector<bool>(n, false);
        // dfs를 이용해서 start부터 시작하는 증가 경로를 찾기
        if (dfs(start))
            ++size;
    }
    return size;
}