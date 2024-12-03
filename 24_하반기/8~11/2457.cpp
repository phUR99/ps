#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
/*
1. 현재 확보한 시간 (시간은 301부터)부터 이 시간 이내에 시작하는 모든 꽃의 생애 주기를 PQ에 집어넣음
PQ는 최대 힙으로, 이 중에서 가장 긴 시간을 찾음
-> 왜 그리디?
1. 탐욕적 선택
제한이 없을 때, 종료 시간이 가장 긴 것을 선택하는 것이 손해를 보지 않음
더 작은 값을 선택한 최적 해가 있다 가정 시 그 해를 더 긴 값으로 교체해도 손해를 보지 않음
2. 최적 부분 구조
이 부분을 제외해도 항상 긴 것을 선택하는 것이 유리함
*/

int main()
{
    fastio;
    int st = 301, ed = 1130;
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        int ma, da, mb, db;
        cin >> ma >> da >> mb >> db;
        arr[i] = {ma * 100 + da, mb * 100 + db};
    }
    sort(arr.begin(), arr.end());
    priority_queue<int> pq;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (st > ed)
            break;
        int a = arr[i].first;
        int b = arr[i].second;
        if (a > st)
        {
            if (pq.empty() || pq.top() < a)
                break;
            st = pq.top();
            cnt++;
        }
        pq.push(b);
    }
    if (!pq.empty() && st <= ed)
    {
        cnt++;
        st = pq.top();
    }

    if (st > ed)
        cout << cnt;
    else
        cout << 0;
    return 0;
}