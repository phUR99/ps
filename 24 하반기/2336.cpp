#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
int b[500005], c[500005];
vector<pair<int, int>> a;

int tree[2000005];
int n, s;

void update(int l, int r, int node, int t, int v)
{
    if (t > r || t < l)
        return;
    if (l == r)
    {
        tree[node] = v;
        return;
    }
    int mid = (l + r) / 2;
    update(l, mid, node * 2, t, v);
    update(mid + 1, r, node * 2 + 1, t, v);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}
int query(int l, int r, int node, int ql, int qr)
{
    if (l > qr || r < ql)
        return 987654321;
    if (l >= ql && r <= qr)
        return tree[node];
    int mid = (l + r) / 2;
    return min(query(l, mid, node * 2, ql, qr), query(mid + 1, r, node * 2 + 1, ql, qr));
}

int main()
{
    fastio;
    cin >> n;
    fill(tree, tree + 4 * n + 1, 987654321);
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        a.push_back({i, t});
    }
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        b[t] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        c[t] = i;
    }
    sort(a.begin(), a.end());
    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        int bb = b[a[i].second];
        int cc = c[a[i].second];
        int mm = query(1, n, 1, 1, bb);
        if (mm > cc)
        {
            answer++;
        }
        update(1, n, 1, bb, cc);
    }
    cout << answer;

    return 0;
}