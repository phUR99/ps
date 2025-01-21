#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
/*
역방향을 어떻게 중복없이 구할까 -> 두 가지  경우로 분할하기
1) 0번 인덱스를 포함하는 경우
2) 0번 인덱스를 포함하지 않는 경우
2)는 전체 합에서 1)을 제외하면 구할 수 있다.
이후 multiset을 이용해서 v가 되는 원소 찾기
다만 multiset의 시간복잡도가 O(logN)이나 상수시간의 문제로 하나씩 찾으면 문제가 생긴다.
a에서 같은 원소 * b 원소의 형식으로 찾은 뒤 방문 처리를 해주자

아니면 합의 제한이 최대 1e6이므로 합의 등장 빈도를 구하는 방식으로 합을 구하면 훨씬 빠르게 작동할 수 있다.
*/
multiset<int> a, b;
int arr1[1005], arr2[1005];

multiset<int> make(int n, int arr[])
{
    multiset<int> ret;
    int sum = accumulate(arr, arr + n, 0);
    ret.insert(sum);
    ret.insert(0);
    for (int i = 1; i < n; i++)
    {
        int tmp = 0;
        for (int j = i; j < n; j++)
        {
            tmp += arr[j];
            ret.insert(tmp);
            ret.insert(sum - tmp);
        }
    }
    return ret;
}
int main()
{
    fastio;
    int v, n, m;
    cin >> v >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    a = make(n, arr1);
    b = make(m, arr2);
    int ret = 0;
    set<int> used;
    for (auto &i : a)
    {
        if (used.count(i))
            continue;
        ret += b.count(v - i) * a.count(i);
        used.insert(i);
    }
    cout << ret;
    return 0;
}