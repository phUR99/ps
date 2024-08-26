#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
#define ll long long
using namespace std;

ll tree[400005];
ll cache[100050];
const ll inf = -1987654321;
/*
세그먼트트리 + dp를 사용하는 방식
점화식 -> d[i] = d[i-1] ~ d[i-d] 까지의 최댓값에 자신을 선택하는 경우
i-1 ~ i-d까지 탐색을 선형으로 한다면 TLE -> 이 구간내의 최댓값을 반환하는쿼리를 세그먼트 트리로 구현하기
*/

void update(int left, int right, int node, int target, ll value)
{
    if (target < left || target > right)
        return;
    if (left == right)
    {
        tree[node] = value;
        return;
    }
    int mid = (left + right) / 2;
    update(left, mid, node * 2, target, value);
    update(mid + 1, right, node * 2 + 1, target, value);
    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}
ll query(int left, int right, int node, int qleft, int qright)
{
    if (left > qright || right < qleft)
        return inf;
    if (left >= qleft && right <= qright)
        return tree[node];
    int mid = (left + right) / 2;
    return max(query(left, mid, node * 2, qleft, qright), query(mid + 1, right, node * 2 + 1, qleft, qright));
}

int main()
{
    fastio;
    int n, d;
    int s = 1;
    cin >> n >> d;
    while (n > s)
    {
        s *= 2;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> cache[i];
    }

    for (int i = 0; i < n; i++)
    {
        cache[i] = max(cache[i], query(0, s - 1, 1, max(i - d, 0), max(0, i - 1)) + cache[i]);
        update(0, s - 1, 1, i, cache[i]);
    }
    cout << *max_element(cache, cache + n);

    return 0;
}