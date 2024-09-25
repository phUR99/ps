#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
int n;
int block[55];
int cache[55][500005];
/*
i번째까지 탐색했을 때의 차이가 diff일 때 작은 쪽의 최댓값
*/

int solve(int cnt, int diff)
{
    if (cnt == n)
    {
        if (diff)
            return -987654321;
        else
            return 0;
    }
    int &ret = cache[cnt][diff];
    if (ret != -1)
        return ret;
    ret = solve(cnt + 1, diff);
    ret = max(ret, solve(cnt + 1, diff + block[cnt]));
    if (block[cnt] > diff)
    {
        // 블록의 위치가 바뀌므로 diff를 더해준다.
        ret = max(ret, solve(cnt + 1, block[cnt] - diff) + diff);
    }
    else
        // 블록의 위치가 바뀌지 않으므로 block의 높이를 더해준다.
        ret = max(ret, solve(cnt + 1, diff - block[cnt]) + block[cnt]);
    return ret;
}

int main()
{
    fastio;
    cin >> n;
    memset(cache, -1, sizeof(cache));

    for (int i = 0; i < n; i++)
    {
        cin >> block[i];
    }
    int answer = solve(0, 0);
    if (answer <= 0)
        cout << -1;
    else
        cout << answer;

    return 0;
}