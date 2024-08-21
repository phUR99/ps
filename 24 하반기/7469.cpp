#include <bits/stdc++.h>
using namespace std;
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
vector<int> tree[400005];
int n, m;
int s = 1;
int L = 1987654321;
int R = -1987654321;
/*
매개변수 탐색까지는 인지, 머지소트 트리는 처음 들어봤음
공간복잡도나 시간복잡도에서 문제가 생길거라 생각했는데
가장 큰 벡터의 크기가 100000이 나오고 그 이후로부터는 다 합해서 100000 * log(100000)정도의 개수
** lower_bound를 사용해서 개수를 +1 하는게 아니라(k가 있으면 예외 처리 해줘야함)
upper_bound를 이용해서 개수를 그대로 세는 테크닉(구간의 차 + 1)을 구현 가능
*/

int query(int left, int right, int node, int qleft, int qright, int k)
{
    if (left > qright || right < qleft)
        return 0;

    if (left >= qleft && right <= qright)
    {
        return upper_bound(tree[node].begin(), tree[node].end(), k) - tree[node].begin();
    }
    int mid = (left + right) / 2;
    return query(left, mid, node * 2, qleft, qright, k) + query(mid + 1, right, node * 2 + 1, qleft, qright, k);
}
int solve(int i, int j, int k)
{
    int l = L;
    int r = R;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        int q = query(1, s, 1, i, j, mid);
        if (q >= k)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}

int main()
{
    fastio;
    cin >> n >> m;

    while (n > s)
    {
        s *= 2;
    }

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        tree[s + i].push_back(tmp);
        L = min(L, tmp);
        R = max(R, tmp);
    }

    for (int i = s - 1; i > 0; i--)
    {
        for (auto e : tree[i * 2])
        {
            tree[i].push_back(e);
        }
        for (auto e : tree[i * 2 + 1])
        {
            tree[i].push_back(e);
        }
    }
    for (int i = 1; i <= 4 * n; i++)
    {
        sort(tree[i].begin(), tree[i].end());
    }

    int i, j, k;
    for (int q = 0; q < m; q++)
    {
        cin >> i >> j >> k;
        cout << solve(i, j, k) << '\n';
    }

    return 0;
}