#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
#define ll long long
using namespace std;
ll tree[400005];
/*
길이가 K고 끝이 arr[i]로 나는 캐시 배열 cache(k, i);
-> cache(k, i) 는 cache(k-1, j) 단 arr[j] < arr[i]를 만족

*/
ll cache[20][100005];
int arr[100005];

void update(int l, int r, int node, int t, ll val)
{
    if (t > r || t < l)
        return;

    tree[node] += val;
    if (l == r)
        return;
    int mid = (l + r) / 2;
    update(l, mid, node * 2, t, val);
    update(mid + 1, r, node * 2 + 1, t, val);
}
ll query(int l, int r, int node, int ql, int qr)
{
    if (r < ql || l > qr)
        return 0;
    if (l >= ql && r <= qr)
        return tree[node];
    int mid = (l + r) / 2;
    return query(l, mid, node * 2, ql, qr) + query(mid + 1, r, node * 2 + 1, ql, qr);
}

int N;

int main()
{
    fastio;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    // 초기화 -> cache[0][0] = 1;
    //
    update(0, N, 1, 0, 1);
    for (int i = 1; i <= 11; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            // idx -> 숫자
            update(0, N, 1, arr[j], cache[i - 1][j]);
            // cache[i-1][j] 중에서 arr[j] - 1보다 작은 개수 세기
            cache[i][j] = query(0, N, 1, 0, arr[j] - 1);
            cache[i][j] %= 1000000007;
        }
        memset(tree, 0, sizeof(tree));
    }
    ll ans = 0;
    for (int i = 1; i <= N; i++)
    {
        ans += cache[11][i];
        ans %= 1000000007;
    }
    cout << ans;

    return 0;
}