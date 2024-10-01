#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)

map<int, int> cnt;
/*
LCS의 아이디어 중 하나..
전에 비슷한 문제를 풀어봤는데 그떄는 x의 범위가 작아서 괜찮았다.
근데 이번처럼 X의 범위가 커지니 map을 쓸 생각을 못했음.
map을 이용하는 DP도 생각하기
1. -> DP 접근.. 인덱스로는 어려움.. 맵을 이용해서 원소의 크기를 넣는 방식으로
2. DP[a] = DP[a-1]+1;
3. 해당하는 원소를 탐색하는 방법은 만족하는 값의 크기부터 뒤로 감소시키면서 돌기

*/

int main()
{
    fastio;
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        if (cnt.count(tmp - 1))
            cnt[tmp] = cnt[tmp - 1] + 1;
        else
            cnt[tmp] = 1;
        arr[i] = tmp;
    }
    int ans = 0;
    int val = 0;
    for (auto &e : cnt)
    {
        if (e.second > ans)
        {
            ans = e.second;
            val = e.first;
        }
    }
    cout << ans << '\n';
    vector<int> ret;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] == val)
        {
            ret.push_back(i + 1);
            val--;
        }
    }
    reverse(ret.begin(), ret.end());
    for (auto &e : ret)
    {
        cout << e << ' ';
    }

    return 0;
}
