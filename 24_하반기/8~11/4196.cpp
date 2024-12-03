#include <bits/stdc++.h>
using namespace std;

#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
vector<vector<int>> adj;
int p[100005];
bool finished[100005];
int indegree[100005];
int id;
int cnt;
int group[100005];
/*
scc에서는 하나만 넘어트려도 모든 정점들이 다 넘어짐 -> scc를 그룹화 해서 하나의 정점으로 모델링
이후 위상정렬의 논리를 적용해서 진입차수 = 0 이면 반드시 넘어트려야함
scc 그룹화 모델링 + 위상정렬
*/
stack<int> s;

int solve(int cur)
{
    p[cur] = ++id;
    s.push(cur);
    int ret = p[cur];
    for (auto nxt : adj[cur])
    {
        // 진입하지 않았다면
        if (p[nxt] == 0)
            ret = min(ret, solve(nxt));
        // 진입한 적은 있지만 완료하지는 않았다면 (부모정점을 만나면 더 작은 값으로 갱신됨)
        else if (!finished[nxt])
            ret = min(ret, p[nxt]);
    }
    // 전부 도달했음(현재가 최소의 ID)
    if (ret == p[cur])
    {
        while (1)
        {
            int now = s.top();
            s.pop();
            // 정점을 하나의 그룹으로 묶어줌
            group[now] = cnt;
            finished[now] = true;
            // 내가 스택에서 나올 때까지
            if (now == cur)
                break;
        }
        cnt++;
    }
    return ret;
}

int main()
{
    fastio;
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int N, M;
        cin >> N >> M;
        adj.clear();
        adj.resize(N + 1);
        memset(indegree, 0, sizeof(indegree));
        memset(finished, false, sizeof(finished));
        memset(p, 0, sizeof(p));
        cnt = 0;
        id = 0;
        for (int i = 0; i < M; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        for (int i = 1; i <= N; i++)
        {
            if (p[i] == 0)
                solve(i);
        }
        for (int i = 1; i <= N; i++)
        {
            for (auto nxt : adj[i])
            {
                // 동일 SCC가 아닐 경우 nxt의 진입차수를 1 증가시켜줌
                if (group[i] != group[nxt])
                    indegree[group[nxt]]++;
            }
        }
        int answer = 0;
        for (int i = 0; i < cnt; i++)
        {
            // 진입차수가 0인 개수를 세줌
            answer += !indegree[i];
        }
        cout << answer << '\n';
    }

    return 0;
}