#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
vector<int> arr, q;
int tree[400005];
int n;
/*
1. 뒤에서부터 넣어주면서 쿼리를 처리해야 하는 이유
맨 뒤에서의 값은 결정이 되어있지만 ,맨 앞에서의 값은 결정이 되어있지 않음
예) 맨 앞에서의 0은 모든 수가 될 수 있지만 맨 뒤에서는 어떤 숫자이든지 하나로 갈 수 밖에 없음
이를 활용해서 1~ N, 1 ~N-1 의 형식으로 맨 뒤를 결정하기
2. 0 인덱스와 1 인덱스.
내가 4등이라는 건 내 앞에 결국 3명이 있다는거 이 점에 주의해서 인덱싱 하기

*/
void update(int l, int r, int node, int t, int v)
{
    if (t > r || t < l)
        return;
    tree[node] += v;
    if (l == r)
        return;
    int mid = (l + r) / 2;
    update(l, mid, node * 2, t, v);
    update(mid + 1, r, node * 2 + 1, t, v);
}
int query(int l, int r, int node, int t)
{
    if (l == r)
        return l;
    int mid = (l + r) / 2;
    if (tree[node * 2] >= t)
        return query(l, mid, node * 2, t);
    else
        return query(mid + 1, r, node * 2 + 1, t - tree[node * 2]);
}

int main()
{
    fastio;
    cin >> n;
    arr.resize(n);
    q.resize(n);
    vector<int> compress;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        compress.push_back(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        update(0, n - 1, 1, i, 1);
    }
    reverse(q.begin(), q.end());
    vector<int> answer;
    for (int i = 0; i < n; i++)
    {
        int now = query(0, n - 1, 1, q[i] + 1);
        answer.push_back(arr[now]);
        update(0, n - 1, 1, now, -1);
    }
    reverse(answer.begin(), answer.end());
    for (int i : answer)
    {
        cout << i << '\n';
    }

    return 0;
}