#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

string scroll;
string bridge[2];
int l, n;
/*
pos : start임 배열 위치 순서를 반대로 해서 메모리 접근 오류남
완전탐색 아이디어
현재 위치에서 체크한 후 다음으로 갈 수 있는 모든 위치에 대해서 체크
-> 현재 위치에서 가능한 지를 체크하면 다음부터는 확인할 필요가 없음
-> 이 부분을 메모이제이션을 활용해서 줄이기

*/
int cache[105][2][25];
int solve(int idx, int start, int pos)
{

    if (idx == l - 1)
        return scroll[idx] == bridge[pos][start];
    if (bridge[pos][start] != scroll[idx])
        return 0;
    int &ret = cache[start][pos][idx];
    if (ret != -1)
        return ret;
    ret = 0;
    int nxtPos = 1 - pos;
    for (int nxt = 1; start + nxt < n; nxt++)
    {
        ret += solve(idx + 1, start + nxt, nxtPos);
    }
    return ret;
}

int main()
{
    fastio;
    memset(cache, -1, sizeof(cache));
    cin >> scroll;
    cin >> bridge[0];
    cin >> bridge[1];
    l = scroll.size();
    n = bridge[0].size();
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        ret += solve(0, i, 0) + solve(0, i, 1);
    }

    cout << ret << '\n';
    return 0;
}