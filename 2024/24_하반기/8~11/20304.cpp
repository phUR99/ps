#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
int n, m;
int dist[1000005];

int main()
{
    fastio;
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int st;
        cin >> st;
        q.push(st);
        dist[st] = 0;
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int k = 0; k < 31; k++)
        {
            int nxt;
            /*
            k번째 비트와 and 연산시 1일 경우
            -> k번째 비트를 0으로 만들어줌
            k번째 비트와 and 연산시 0일 경우
            -> k번째 비트를 1으로 만들어줌
            이후 bfs 실행하면서 dist 배열 채우기
            */
            if (cur & (1 << k))
            {
                nxt = cur & ~(1 << k);
            }
            else
            {
                nxt = cur | (1 << k);
            }
            if (nxt > n)
                continue;
            if (dist[nxt] != -1)
                continue;

            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }
    int answer = -1;
    for (int i = 0; i <= n; i++)
    {
        answer = max(answer, dist[i]);
    }
    cout << answer;

    return 0;
}