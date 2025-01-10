#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
/*
이분그래프에서의 최대 매칭 == 최소 버텍스 커버(쾨닉의 정리)
그래프 모델링
row -> col 형태로 이분 그래프 모델링
row가 col을 선택하는 형태로 최대 매칭 구하기
다른 row가 col을 선택할 수 없으므로(col은 이미 매칭되어있으므로)
*/
int n, k;
int row[505];
int col[505];
bool visited[505];
vector<vector<int>> adj;
bool dfs(int r)
{
    if (visited[r])
        return false;
    visited[r] = true;
    for (auto &c : adj[r])
    {
        if (col[c] == -1 || dfs(col[c]))
        {
            row[r] = c;
            col[c] = r;
            return true;
        }
    }
    return false;
}

int bipartiteMatching()
{
    int size = 0;
    memset(row, -1, sizeof(row));
    memset(col, -1, sizeof(col));
    for (int i = 1; i <= n; i++)
    {
        memset(visited, 0, sizeof(visited));
        if (dfs(i))
            size++;
    }
    return size;
}
int main()
{
    fastio;
    cin >> n >> k;
    adj.resize(n + 1);
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    int ret = bipartiteMatching();
    cout << ret;
    return 0;
}