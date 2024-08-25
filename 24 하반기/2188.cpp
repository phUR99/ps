#include <bits/stdc++.h>
using namespace std;
int N, M;
bool visited[205];
int match[205];
vector<vector<int>> adj;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)

bool solve(int cur)
{
    visited[cur] = true;
    for (auto nxt : adj[cur])
    {
        // 매칭이 안되있거나, 매칭이 되어있다면 방문한 지점이 아니고, 새로 매칭이 가능할 때
        if (match[nxt] == 0 || !visited[match[nxt]] && solve(match[nxt]))
        {
            match[nxt] = cur;
            return true;
        }
    }
    return false;
}

int main()
{
    fastio;
    cin >> N >> M;
    adj.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        int cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; j++)
        {
            int nxt;
            cin >> nxt;
            adj[i].push_back(nxt);
        }
    }
    int answer = 0;
    for (int i = 1; i <= N; i++)
    {
        memset(visited, false, sizeof(visited));
        if (solve(i))
            answer++;
    }
    cout << answer;

    return 0;
}