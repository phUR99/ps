#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long

int main()
{
    fastio;

    int m;
    cin >> m;
    vector<pair<int, int>> arr;
    while (1)
    {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;
        if (b <= a)
            continue;
        // 시작점의 오름차순으로, 시작점이 같다면 끝 점의 내림차순으로
        arr.push_back({a, -b});
    }
    sort(arr.begin(), arr.end());
    int st = 0;
    int cnt = 0;
    auto iter = arr.begin();
    /* ************************************** */
    // while문에 이 조건을 넣는 것을 생각하지 못함
    while (st < m)
    {
        int max_end = st;
        // 현재 iter부터 x좌표가 st에 포함이 되는 구간의 y좌표를 전부 확인하면서 그 중에서 최대를 st로 변경해줌
        // 시작점의 오름차순으로 정렬되어있으므로 전부 한번씩 탐색할 수 있음
        while (iter != arr.end() && iter->first <= st)
        {
            max_end = max(max_end, -iter->second);
            iter++;
        }
        // 가능한 범위까지 전부 탐색했을 때 st를 갱신할 수 없다면 더 이상 진행할 수 없다
        if (max_end == st)
        {
            cout << 0;
            return 0;
        }
        st = max_end;
        cnt++;
    }
    cout << cnt;
    return 0;
}