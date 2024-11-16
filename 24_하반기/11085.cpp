#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
/*
크루스칼 알고리즘 채용
1. 역순으로 트리를 완성하다 보면 C와 V가 이어지는 순간이 옴
그 때의 값을 출력하기 ( 그 이상으로는 해를 구성할 수 없음)
2. 이렇게 하는게 왜 당연한가?
답이 너비의 최솟값의 최대화를 원하기 때문에
-> 사용하지 않은 간선은 다음 노드를 체크하는 과정에서 자연스럽게 없어진다.

*/
int p, w, c, v;
int parent[1005];
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
    if (u == v)
        return;
    parent[u] = v;
}
int main()
{
    fastio;
    cin >> p >> w >> c >> v;
    vector<vector<int>> arr(w, vector<int>(3));
    for (int i = 0; i < w; i++)
    {
        cin >> arr[i][1] >> arr[i][2] >> arr[i][0];
    }
    for (int i = 0; i < p; i++)
    {
        parent[i] = i;
    }

    sort(arr.begin(), arr.end(), greater<>());
    for (int i = 0; i < w; i++)
    {
        int width = arr[i][0];
        int uu = arr[i][1];
        int vv = arr[i][2];
        merge(uu, vv);
        if (find(c) == find(v))
        {
            cout << width;
            return 0;
        }
    }

    return 0;
}