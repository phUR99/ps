#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
/*
처음 이분매칭을 돌렸을 때의 최대 매칭 수를 구하고
다시 한번 더 이분매칭을 돌렸을 때의 매칭 수를 구한다.
(매칭이 안된 일에 대해서 한번 더 가능한지)
시간초과 주의 -> adj를 n으로 하면 안되고 그것보다는 줄여야 한다
*/
int n, m, k;
vector<int> adj[1005];
int aMatch[1005], bMatch[1005];
bool visited[1005];

bool dfs(int a)
{
    if (visited[a])
        return false;
    visited[a] = true;
    for (auto &b : adj[a])
    {
        if (bMatch[b] == -1 || dfs(bMatch[b]))
        {
            bMatch[b] = a;
            aMatch[a] = b;
            return true;
        }
    }
    return false;
}

int bipartiteMatching()
{
    memset(aMatch, -1, sizeof(aMatch));
    memset(bMatch, -1, sizeof(bMatch));
    int size = 0;
    for (int i = 0; i < n; i++)
    {
        memset(visited, 0, sizeof(visited));
        if (dfs(i))
            size++;
    }
    int extra = 0;
    for (int i = 0; i < n; i++)
    {
        memset(visited, 0, sizeof(visited));
        if (dfs(i))
            extra++;
        if (extra == k)
            break;
    }
    return size + extra;
}

int main()
{
    fastio;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        while (t--)
        {
            int b;
            cin >> b;
            adj[i].push_back(b);
        }
    }
    int ret = bipartiteMatching();
    cout << ret;
    return 0;
}