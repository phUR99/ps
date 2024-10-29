#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
/*
나이브한 아이디어 : O(nm) -> 각 원소에 대해서 m번씩 탐색하면서 cnt가 K보다 큰 지를 판단
-> nm이 충분히 크니까 불가능 (병목 현상이 일어나는 지점)
최적화 아이디어: 처음에 m번의 탐색을 끝냈다면 1 ~ m까지는 탐색을 할 필요가 없음 (불필요한 반복임)
따라서 양쪽 끝의 원소만 제거/추가하면 O(n)으로 최적화 가능 ->
모든 원소를 탐색해야하니 O(n) 이하 불가능
-->슬라이딩 윈도우를 활용하기
-> 병목현상 2 : 빈도를 체크하기 위한 배열을 1e6으로 선언했을 때 처음 탐색 시 전부 돌아야 해서 시간초과
b의 원소들만 넣고 체크


*/
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (auto &i : a)
    {
        cin >> i;
    }
    map<int, int> b, c;
    for (int i = 0; i < m; i++)
    {
        int e;
        cin >> e;
        b[e]++;
    }
    for (int i = 0; i < m; i++)
    {
        int e = a[i];
        c[e]++;
    }
    int cnt = 0;
    int ret = 0;
    for (auto iter : b)
    {
        cnt += min(b[iter.first], c[iter.first]);
    }
    if (cnt >= k)
        ret++;
    for (int i = 0; i < n - m; i++)
    {
        int r = a[i + m];
        int l = a[i];
        if (c[l] <= b[l])
            cnt--;
        c[l]--;
        c[r]++;
        if (c[r] <= b[r])
            cnt++;
        ret += (cnt >= k);
    }
    cout << ret << '\n';
}

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
