#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
/*
끝나는 시간의 오름차순으로 정렬을 하는 이유
1. 0부터 시작하는 긴 선분을 완성하는 느낌으로(가장 작은 범위부터 탐색하기)
탐욕적 선택 증명
가장 빨리 끝나는 시간부터 확인했을 때 최적해가 나오는 이유
그렇지 않은 해가 있다고 가정(xi보다 더 빨리 탐색해서 최적해가 나왔다)
두 값을 바꿔서 매칭해도  손해는 없음
*/

int main()
{
    fastio;

    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    int c, n;
    cin >> c >> n;
    vector<int> arr(c);
    vector<bool> used(c, false);
    for (auto &i : arr)
    {
        cin >> i;
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        pq.push({y, x});
    }
    int ret = 0;
    while (!pq.empty())
    {
        int x = pq.top()[1];
        int y = pq.top()[0];
        pq.pop();
        for (int i = 0; i < c; i++)
        {
            if (x <= arr[i] && y >= arr[i] && !used[i])
            {
                ret++;
                used[i] = true;
                break;
            }
        }
    }

    cout << ret;

    return 0;
}