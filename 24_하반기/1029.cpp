#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
/*
1. 참조적 투명성을 유지하기 위해서 3차원 설계하기
-> 현재 소유자와, 현재 상태만으로는 참조적 투명성을 유지할 수 없음
두 개가 같아도 살 수 있는 가격이 달라질 수 있기 때문에
따라서 현재 가격인 변수를 반영하여 DP 설계를 해야 참조적 투명성을 유지할 수 있다.
*/
int n;
int board[15][15];
int cache[15][10][1 << 15];
static int callNumber = 0;
int maxNum(int index, int currentPrice, int state)
{
    callNumber++;
    int &ret = cache[index][currentPrice][state];
    if (ret != -1)
        return ret;
    ret = 1;
    for (int nxt = 0; nxt < n; nxt++)
    {

        if (state & (1 << nxt))
            continue;
        if (board[index][nxt] >= currentPrice)
        {
            int nxtstate = state | (1 << nxt);
            ret = max(ret, maxNum(nxt, board[index][nxt], nxtstate) + 1);
        }
    }
    return ret;
}

int main()
{
    fastio;
    memset(cache, -1, sizeof(cache));
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            board[i][j] = c - '0';
        }
    }
    int ret = max(1, maxNum(0, 0, 1));
    cout << ret << '\n';
    // cout << callNumber;
    return 0;
}