#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
int T, N, M;
int adj[505][505];
vector<int> prize, answer;
int degree[505];
/*
?는 없다 -> ?가 나오는 상황은 degree가 0인 노드가 2개 이상 등장해서 순서가 2개 이상 나오는 경우인데
인접행렬을 이용해서 모든 노드에 대해서 위상정렬을 해주면 절대 0인 노드가 2개 이상 등장하는 경우는 없음
사이클이 생기는 경우는 위상정렬을 모두 했을 때 위상정렬의 벡터가 사이즈가 N이 아니면 위상정렬 불가능
*/
int main()
{
    fastio;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> N;
        memset(adj, 0, sizeof(adj));
        memset(degree, 0, sizeof(degree));
        prize.clear();
        prize.resize(N);
        answer.clear();
        for (int i = 0; i < N; i++)
        {
            cin >> prize[i];
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                adj[prize[i]][prize[j]] = 1;
                degree[prize[j]]++;
            }
        }
        cin >> M;
        for (int i = 0; i < M; i++)
        {
            int u, v;
            cin >> u >> v;
            if (adj[u][v])
            {
                adj[u][v] = 0;
                adj[v][u] = 1;
                degree[v]--;
                degree[u]++;
            }
            else
            {
                adj[v][u] = 0;
                adj[u][v] = 1;
                degree[u]--;
                degree[v]++;
            }
        }
        queue<int> q;
        for (int i = 1; i <= N; i++)
        {
            if (degree[i] == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            answer.push_back(cur);
            for (int i = 1; i <= N; i++)
            {
                if (adj[cur][i])
                {
                    degree[i]--;
                    if (degree[i] == 0)
                        q.push(i);
                }
            }
        }
        if (answer.size() != N)
            cout << "IMPOSSIBLE\n";
        else
        {
            for (auto i : answer)
            {
                cout << i << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}