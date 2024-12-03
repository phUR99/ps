#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
int cache[10005][10];
int now[10005], goal[10005];
int n;
// 현재 인덱스, 왼쪽으로 돌아간 정도
/*
1.현재값이랑 목표값이랑 두 개를 같이 생각하려고 하면 문제가 너무 어려워짐
현재값은 0으로 고정시키고 목표값을 현재값 대비 오른쪽으로 얼마나 떨어져있는지만 체크
2.c++에서 모듈러 연산은 음수를 고려하지 않음 -> 반드시 양수로 만들어줘야함
3.문제 지문 잘 읽기. 왼쪽으로 돌리는게 작아지는 게 아니라 커지는거임

*/
int solve(int cur, int left)
{
    if (cur == n)
        return 0;
    int &ret = cache[cur][left];
    if (ret != -1)
        return ret;
    ret = 0;
    // 현재값 0 기준으로 오른쪽으로 몇칸 떨어저있는지
    int state = (goal[cur] + left) % 10;

    ret = min(solve(cur + 1, (left - state + 10) % 10) + state, solve(cur + 1, left) + 10 - state);
    return ret;
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
        now[i] = c - '0';
    }
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        goal[i] = c - '0';
    }
    for (int i = 0; i < n; i++)
    {
        goal[i] -= now[i];
        goal[i] = (goal[i] + 10) % 10;
    }

    int answer = solve(0, 0);
    cout << answer << '\n';

    return 0;
}