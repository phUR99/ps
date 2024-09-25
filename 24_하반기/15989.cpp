#include <bits/stdc++.h>
using namespace std;
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

int arr[10005];
int cache[4][10005];
/*
현재 함수: N ~ 1 까지의 정수 n의 조합을 만드는 함수
다음 함수: N-1 ~ 1까지의 정수 n -cur 의 조합을 만드는 함수
개수만 정보에 넣겠다는 것은 인덱스를 한번만 사용하고 나머지는 사용하지 않겠다.
1, 0
1, 1
1, 2.. 이런 정보는 모두 알 수 있음 -> cache[1][2] = 1로 만들 수 있는 개수
cache[2][3] = 1, 2로 만들 수 있는 3의 개수..
*/
int solve(int cur, int val)
{
    if (val == 0)
        return 1;
    if (cur == 0)
        return 0;

    int &ret = cache[cur][val];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int i = 0; i <= val; i += arr[cur])
    {
        ret += solve(cur - 1, val - i);
    }
    return ret;
}
int N, T;

int main()
{
    fastio;
    cin >> T;
    memset(cache, -1, sizeof(cache));

    for (int i = 1; i <= 3; i++)
    {
        arr[i] = i;
    }
    for (int t = 0; t < T; t++)
    {
        cin >> N;
        int answer = solve(3, N);
        cout << answer << '\n';
    }
    return 0;
}