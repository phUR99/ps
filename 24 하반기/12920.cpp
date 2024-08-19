#include <bits/stdc++.h>
using namespace std;
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
int N, M;
vector<vector<int>> cache;
vector<pair<int, int>> arr;

/*
개수가 여러개인 냅색 -> 개수가 작으면 상관 없겠지만 현재의 경우에서는 100^10000 의 형태
따라서 개수를 줄이는 방법 -> logN의 형식 취하기
각 수를 1.. 2.. 4.. 의 형태로 이진수로 표현할 수 있게 변형
** 단, 이진수로 표현하기 위해서 비트마스킹 기법을 사용하는 것이 아님
-> 사용하는 개수의 모든 형태를 표현할 수 없음
개수에서 빼면서 벡터를 만듦.
*/

int solve(int cur, int now)
{
    if (now < 0)
        return -987654321;
    if (now == 0 || cur == -1)
        return 0;
    int &ret = cache[cur][now];
    if (ret != -1)
        return ret;

    ret = max(solve(cur - 1, now), solve(cur - 1, now - arr[cur].first) + arr[cur].second);
    return ret;
}

int main()
{
    fastio;
    cin >> N >> M;

    int w, v, k;
    for (int i = 1; i <= N; i++)
    {
        cin >> w >> v >> k;
        int p = 1;
        while (k > 0)
        {
            int now = min(p, k);
            arr.push_back({w * now, v * now});
            k -= now;
            p <<= 1;
        }
    }
    int len = arr.size();
    cache.resize(len);
    for (int i = 0; i < len; i++)
    {
        cache[i].resize(M + 1, -1);
    }

    int answer = solve(len - 1, M);
    cout << answer;

    return 0;
}