#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
int parent[200005];
vector<set<int>> p;

int find(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = find(parent[u]);
}
void merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return;
    if (p[u].size() < p[v].size())
        swap(u, v);
    parent[v] = u;
    for (auto it : p[v])
    {
        p[u].insert(it);
    }
    p[v].clear();
}
int n, q;

int main()
{
    fastio;
    cin >> n >> q;
    p.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        p[i].insert(i);
    }

    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int u, v;
            cin >> u >> v;
            merge(u, v);
        }
        else
        {
            int u, k;
            cin >> u >> k;
            u = find(u);
            if (p[u].size() < k)
                cout << -1 << '\n';
            else
            {
                auto it = p[u].end();
                while (k--)
                {
                    it = prev(it);
                }
                cout << *it << '\n';
            }
        }
    }

    return 0;
}
