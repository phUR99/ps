#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
/*
선을 하나씩 포함하면서 분리집합을 이용해 쿼리 판정
-> 다만 N의 개수가 100000이기 때문에 N^2로는 할 수 없음
선을 하나씩 보면서 연장하는 방식으로(작은 좌표부터) 한번만 보고 확인 가능
*/
int left[100005];
int right[100005];
int parent[100005];
int n, q;
int find(int u)
{
    if (parent[u] == u)
        return u;
    return parent[u] = find(parent[u]);
}
void merge(int u, int v)
{
    u = find(u);
    v = find(v);
    parent[u] = v;
}

int main()
{
    fastio;
    cin >> n >> q;
    vector<array<int, 3>> line;
    for (int i = 0; i < n; i++)
    {
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        line.push_back({x1, x2, i + 1});
    }
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    sort(line.begin(), line.end());
    int cur = line[0][1];
    int now = line[0][2];
    for (int i = 1; i < n; i++)
    {
        int xl = line[i][0];
        if (xl <= cur)
        {
            merge(now, line[i][2]);
            cur = max(cur, line[i][1]);
        }
        else
        {
            cur = line[i][1];
            now = line[i][2];
        }
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (find(a) == find(b))
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }

    return 0;
}