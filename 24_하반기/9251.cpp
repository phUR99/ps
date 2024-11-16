#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
int cache[1005][1005];
string str1, str2;
/*
완전탐색
str를 탐색하면서 하나씩 관찰
-> idx1, idx2 을 고정할 수 있다면 항상 동일한 값(참조적 투명성 만족)
cache[idx1][idx2] = idx1, idx2에서 시작해서 얻을 수 있는 최대 LCS
-> 경우의 수는 3가지
1. 같다면 현재 값을 선택하고 인덱스 2개를 동시에 올리기
2. 다르다면 한쪽의 인덱스를 올리기

*/
int solve(int idx1, int idx2)
{

    if (idx1 == str1.size() || idx2 == str2.size())
        return 0;
    int &ret = cache[idx1][idx2];
    if (ret != -1)
        return ret;
    ret = 0;
    if (str1[idx1] == str2[idx2])
        ret = max(ret, solve(idx1 + 1, idx2 + 1) + 1);
    ret = max(ret, solve(idx1 + 1, idx2));
    ret = max(ret, solve(idx1, idx2 + 1));
    return ret;
}

int main()
{
    fastio;
    memset(cache, -1, sizeof(cache));
    cin >> str1 >> str2;
    int ret = solve(0, 0);
    cout << ret << '\n';
    return 0;
}