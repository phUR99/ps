#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
int n, m;

int tree[(1 << 19) + 1];
void update(int l, int r, int n, int t, int c, int v)
{
    if (l > t || r < t)
        return;
    if (l == r)
    {
        tree[n] = v;
        return;
    }
    int m = (l + r) / 2;
    update(l, m, n * 2, t, c - 1, v);
    update(m + 1, r, n * 2 + 1, t, c - 1, v);
    if (c % 2 == 0)
        tree[n] = tree[n * 2] ^ tree[n * 2 + 1];
    else
        tree[n] = tree[n * 2] | tree[n * 2 + 1];
}

int main()
{
    fastio;
    cin >> n >> m;
    int l = 1;
    int r = (1 << n);
    for (int i = 1; i <= (1 << n); i++)
    {
        int now;
        cin >> now;
        update(l, r, 1, i, n, now);
    }

    while (m--)
    {
        int p, b;
        cin >> p >> b;
        update(l, r, 1, p, n, b);
        cout << tree[1] << '\n';
    }

    return 0;
}
