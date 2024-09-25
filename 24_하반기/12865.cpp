#include <bits/stdc++.h>
using namespace std;
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
int w[105];
int v[105];
int N, K;
/*
1. 배열을 탐색하면서 최댓값을 반환하는 함수(N ~ 1)
2. 다음 함수의 형태는 N -1 ~ 1...
3. 초기(인덱스 1) 일 때 (1, w[1]), (1, 0)이 계속 반복되는 것을 발견
4. 메모이제이션 -> (idx, weight)을 저장하는 배열로 연속되는 부분문제 해결
5. cache[i][w] = max(cache[i-1][w], cache[i-1][w -w[cnt]] + v[cnt])의 점화식
*/
/*


*/

int cache[105][100005];

int solve(int cnt, int weight)
{
    if (weight < 0)
        return -987654321;
    if (cnt == 0)
        return 0;
    int &ret = cache[cnt][weight];
    if (ret != -1)
        return ret;
    ret = 0;
    ret = max(solve(cnt - 1, weight), solve(cnt - 1, weight - w[cnt]) + v[cnt]);
    return ret;
}

int main()
{
    fastio;
    cin >> N >> K;
    memset(cache, -1, sizeof(cache));

    for (int i = 1; i <= N; i++)
    {
        cin >> w[i] >> v[i];
    }
    int answer = solve(N, K);
    cout << answer;

    return 0;
}