#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
vector<array<int, 2>> arr;
vector<int> answer;
/*
좌석을 어떻게 최소로 분배할까?
1. 시작 시간 기준으로 정렬
2. 끝나는 시간의 오름차순으로 정렬한 뒤 체크
3. 좌석을 최소 힙으로 관리(핵심)
*/
int main()
{
    fastio;
    int n;
    cin >> n;
    arr.resize(n);
    answer.resize(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }
    sort(arr.begin(), arr.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    priority_queue<int, vector<int>, greater<int>> order;
    for (int i = 0; i < n + 1; i++)
    {
        order.push(i);
    }
    int M = 0;
    for (int i = 0; i < n; i++)
    {
        int l = arr[i][0];
        int r = arr[i][1];
        while (!pq.empty() && pq.top().first < l)
        {
            order.push(pq.top().second);
            pq.pop();
        }
        pq.push({r, order.top()});
        answer[order.top()]++;
        order.pop();
        M = max(order.top(), M);
    }
    cout << M << '\n';
    for (int i = 0; i < M; i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}