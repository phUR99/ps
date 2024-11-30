#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
/*
시작 순서대로 정렬
끝나는 순서대로 최소 힙을 구성
한 강의를 집어 넣기 전에 강의 전에 끝나는 강의가 있는지 확인하고 넣기
그 때의 사이즈의 최대가 정답
*/

int main()
{
    fastio;
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n + 1);
    for (int i = 0; i < n; i++)
    {
        int idx, st, ed;
        cin >> idx >> st >> ed;
        arr[idx] = {st, ed};
    }
    sort(arr.begin() + 1, arr.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    int ret = 0;
    for (int i = 1; i <= n; i++)
    {
        int st = arr[i].first;
        int ed = arr[i].second;
        while (!pq.empty() && pq.top() <= st)
        {
            pq.pop();
        }
        pq.push(ed);
        ret = max(ret, (int)pq.size());
    }
    cout << ret;
    return 0;
}