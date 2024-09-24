#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
int st[50050];
int tree[400050];

int query(int l, int r, int n, int ql, int qr);
void update(int l, int r, int n, int t, int d);
/*
스위핑의 아이디어
-> st와 ed를 비교해서 그 사이에 있는지를 체크 !
양 끝이 안에 있을 때를 제거하기 위해서 다시 나온다면 제거하면서 체크
*/

int query(int l, int r, int n, int ql, int qr)
{
    if (r < ql || l > qr)
        return 0;
    if (l >= ql && r <= qr)
        return tree[n];
    int mid = (l + r) / 2;
    return query(l, mid, n * 2, ql, qr) + query(mid + 1, r, n * 2 + 1, ql, qr);
}
void update(int l, int r, int n, int t, int d)
{
    if (l > t || r < t)
        return;
    if (l == r)
    {
        tree[n] += d;
        return;
    }
    int mid = (l + r) / 2;
    update(l, mid, n * 2, t, d);
    update(mid + 1, r, n * 2 + 1, t, d);
    tree[n] = tree[n * 2] + tree[n * 2 + 1];
}
int main()
{
    fastio;
    int n;
    cin >> n;
    long long answer = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
        int cur;
        cin >> cur;
        if (st[cur] == 0)
        {
            st[cur] = i;
            update(1, 2 * n, 1, i, 1);
        }
        else
        {
            answer += query(1, 2 * n, 1, st[cur] + 1, i - 1);
            update(1, 2 * n, 1, st[cur], -1);
        }
    }
    cout << answer;

    return 0;
}
