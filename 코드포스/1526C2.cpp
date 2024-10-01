#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
int n;
/*
1. n = 2e5이므로 o(n) / o(nlogn) 풀이 필요
-> 중간에 반드시 원소를 선택하는 게 아니라 필요시 되돌아가는 방법 필요
2. 음수가 아닌 원소는 반드시 선택하는 게 유리
-> 음수일 경우에는 일단 선택한 후에 체력이 부족해지면 버리는 방식으로...

*/

int main()
{
    fastio;
    cin >> n;
    long long sum = 0;
    priority_queue<int> pq;

    for (int i = 0; i < n; i++)
    {
        int now;
        cin >> now;
        sum += now;
        pq.push(-now);
        if (sum < 0)
        {
            int cur = pq.top();
            pq.pop();
            sum += cur;
        }
    }
    cout << pq.size();
    return 0;
}
