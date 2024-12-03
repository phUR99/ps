#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
int state[10005];
int cache[10005][10];
pair<int, int> trace[10005][10];
int n;
/*
최적 해를 잡는 것까지는 쉬웠으나 추적이 살짝 어려웠음
-> 최적해를 따라간다고 해서 어떻게 움직였는지 파악이 어려움
-> 따라서 따른 배열을 하나 파서 반환값의 정보를 기록해두고 역추적하기

*/
int solve(int begin, int offset)
{
    if (begin == n)
        return 0;
    int &ret = cache[begin][offset];
    if (ret != -1)
        return ret;
    int turned_left = (-offset - state[begin] + 20) % 10;
    int turned_right = 10 - turned_left;
    int l = turned_left + solve(begin + 1, (offset + turned_left) % 10);
    int r = turned_right + solve(begin + 1, offset);
    if (l <= r)
    {
        trace[begin][offset].first = turned_left;
        trace[begin][offset].second = (offset + turned_left) % 10;
    }
    else
    {
        trace[begin][offset].first = -turned_right;
        trace[begin][offset].second = offset;
    }
    return ret = min(l, r);
}

int main()
{
    fastio;
    memset(cache, -1, sizeof(cache));

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        state[i] = c - '0';
    }
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        state[i] -= c - '0';
    }
    cout << solve(0, 0) << '\n';
    int off = 0;
    for (int i = 0; i < n; i++)
    {
        auto cur = trace[i][off];
        cout << i + 1 << ' ';
        cout << cur.first << '\n';
        off = cur.second;
    }

    return 0;
}