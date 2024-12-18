#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, k, m, l;

int classes[10];
int cache[10][1 << 15];
int prerequisite[1 << 15];
int solve(int semester, int state)
{
    if (__builtin_popcount(state) >= k)
        return 0;
    if (semester == m)
        return 987654321;
    int &ret = cache[semester][state];
    if (ret != -1)
        return ret;
    // 차집합 연산
    ret = 987654321;
    int canTake = classes[semester] & ~state;
    if (int i = 0; i < n; i++)
    {
        if ((canTake & (1 << i)) && (state & prerequisite[i]) != prerequisite[i])
            canTake &= ~(1 << i);
    }
    for (int nxtState = state; nxtState > 0; nxtState = (nxtState - 1) & state)
    {
        if (__builtin_popcount(nxtState) > l)
            continue;
        ret = min(ret, solve(semester + 1, nxtState | state) + 1);
    }
    ret = min(ret, solve(semester + 1, state));
    return ret;
}
int main()
{
    fastio;

    return 0;
}