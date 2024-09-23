#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
#define INF 987654321
#define MAX 100000 + 101
/*
층이랑 엘리베이터랑 구분해서 그래프 만들기
층 ~ 엘리베이터 연결
*/
int N, M, S, E;
int dist[MAX];
int par[MAX];
vector<int> adj[MAX];

void bfs()
{

    queue<int> q;
    fill(par, par + MAX, -1);
    fill(dist, dist + MAX, INF);
    q.push(E);
    dist[E] = 0;
    while (!q.empty())
    {
        int here = q.front();
        q.pop();
        for (auto next : adj[here])
        {
            if (dist[next] == INF)
            {
                dist[next] = dist[here] + 1;
                par[next] = here;
                q.push(next);
            }
        }
    }
}

int main()
{

    scanf("%d%d", &N, &M);
    for (int m = 1; m <= M; m++)
    {
        int a, b;
        scanf("%d%d", &b, &a);
        for (int n = b; n <= N; n += a)
        {
            adj[n].push_back(m + 100000);
            adj[m + 100000].push_back(n);
        }
    }
    scanf("%d%d", &S, &E);
    bfs();
    if (dist[S] == INF)
        printf("-1\n");
    else
    {
        printf("%d\n", dist[S] / 2);
        for (int i = par[S]; i >= 0; i = par[par[i]])

            printf("%d\n", i - 100000);
    }

    return 0;
}
