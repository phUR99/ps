/*
업데이트가 없는 구간 쿼리들을 처리하는 알고리즘(오프라인 쿼리 처리)
제곱근 분할법을 활용
배열을 원소가 K = sqrt(N)개의 버킷으로 분할
아래의 조건 중 하나를 만족하는 경우 Q1을 Q2보다 먼저 처리하기
1. [s1/k] < [s2/k] (q1의 시작점의 버킷이 더 왼쪽일 때)
2. [s1/k] = [s2/k] && e1 < e2 (동일할 때 종료 시점이 더 오른쪽일 때)
시간 복잡도 계산
쿼리 정렬 O(QlogQ + Nlog(N))
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
int sqrtN;

struct Query
{
    int idx, s, e;
    bool operator<(Query &x)
    {
        if (s / sqrtN != x.s / sqrtN)
            return s / sqrtN < x.s / sqrtN;
        return e < x.e;
    }
};

vector<Query> query;
vector<int> v;
ll res = 0;
ll ans[101010];

int main()
{
    fastio;
    int n, q;
    cin >> n >> q;
    sqrtN = sqrt(n);
    v.resize(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < q; i++)
    {
        int s, e;
        cin >> s >> e;
        query.push_back({i, s, e});
    }
    sort(query.begin(), query.end());

    int s = query[0].s, e = query[0].e;
    for (int i = s; i <= e; i++)
    {
        res += v[i];
    }
    ans[query[0].idx] = res;

    for (int i = 1; i < q; i++)
    {
        while (s < query[i].s)
            res -= v[s++];
        while (s > query[i].s)
            res += v[--s];
        while (e < query[i].e)
            res += v[++e];
        while (e > query[i].e)
            res -= v[e--];
        ans[query[i].idx] = res;
    }
    for (int i = 0; i < q; i++)
        cout << ans[i] << "\n";
    return 0;
}
