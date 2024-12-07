#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long

struct node
{
    int x, y, r;
};

node info[105];
vector<vector<int>> adj;
bool visited[105];
bool cmp(const int a, const int b)
{
    return info[b].r < info[a].r;
}

bool isInclude(int child, int x)
{
    if (info[x].r >= info[child].r)
        return false;
    int dist = (info[child].x - info[x].x) * (info[child].x - info[x].x) +
               (info[child].y - info[x].y) * (info[child].y - info[x].y);
    return dist <= (info[child].r - info[x].r) * (info[child].r - info[x].r);
}

void makeTree(int root, int x)
{
    visited[root] = true;
    for (int child : adj[root])
    {
        if (visited[child])
            continue;
        if (isInclude(child, x))
        {
            makeTree(child, x);
            return;
        }
    }
    adj[root].push_back(x);
    adj[x].push_back(root);
    return;
}
int mxNode = 0;
int mxDist = 0;
void maxDepth(int root, int dist)
{
    int ret = 0;
    visited[root] = true;
    if (dist > mxDist)
    {
        mxNode = root;
        mxDist = dist;
    }

    for (int there : adj[root])
    {
        if (visited[there])
            continue;
        maxDepth(there, dist + (there != 0 && root != 0));
    }
}

void solve()
{
    int n;
    cin >> n;
    adj.clear();
    adj.resize(n + 1);
    mxNode = 0;
    mxDist = 0;
    vector<int> castles;
    for (int i = 1; i <= n; i++)
    {
        castles.push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> info[i].x >> info[i].y >> info[i].r;
    }
    sort(castles.begin(), castles.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        memset(visited, 0, sizeof(visited));
        makeTree(0, castles[i]);
    }
    memset(visited, 0, sizeof(visited));
    maxDepth(0, 0);
    memset(visited, 0, sizeof(visited));
    maxDepth(mxNode, 0);
    cout << mxDist << '\n';
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