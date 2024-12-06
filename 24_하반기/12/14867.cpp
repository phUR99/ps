#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
/*
상태공간 N^2의 형태를 띄고 있음(N=100000이니 절대 불가능할듯)
그러나 예제를 봤을 때 상태공간 크기에 비해서 사용하는 절대 양은 한정적임
따라서 해싱을 이용해서 푸는 풀이

2.
추가적으로 연산을 사용하기 위해서는 한쪽 물통은 반드시 꽉 차거나 비는 2가지 경우
2가지 경우 * 어느 물통 * N = 4N으로 상태공간을 압축할 수 있음
*/
int a, b, c, d;
int bfs()
{
    map<pair<int, int>, int> dist;
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[{0, 0}] = 0;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int wa = cur.first;
        int wb = cur.second;
        if (dist.count({wa, 0}) == 0)
        {
            dist[{wa, 0}] = dist[cur] + 1;
            q.push({wa, 0});
        }
        if (dist.count({0, wb}) == 0)
        {
            dist[{0, wb}] = dist[cur] + 1;
            q.push({0, wb});
        }
        if (dist.count({wa, b}) == 0)
        {
            dist[{wa, b}] = dist[cur] + 1;
            q.push({wa, b});
        }
        if (dist.count({a, wb}) == 0)
        {
            dist[{a, wb}] = dist[cur] + 1;
            q.push({a, wb});
        }
        if (dist.count({min(wa + wb, a), max(0, wa + wb - a)}) == 0)
        {
            dist[{min(wa + wb, a), max(0, wa + wb - a)}] = dist[cur] + 1;
            q.push({min(wa + wb, a), max(0, wa + wb - a)});
        }
        if (dist.count({max(0, wa + wb - b), min(wa + wb, b)}) == 0)
        {
            dist[{max(0, wa + wb - b), min(wa + wb, b)}] = dist[cur] + 1;
            q.push({max(0, wa + wb - b), min(wa + wb, b)});
        }
    }
    if (dist.count({c, d}) == 0)
        return -1;
    return dist[{c, d}];
}

int main()
{
    fastio;
    cin >> a >> b >> c >> d;
    int ret = bfs();
    cout << ret;
    return 0;
}