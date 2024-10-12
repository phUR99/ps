#include <bits/stdc++.h>
using namespace std;
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
/*
1. x 위치를 확인하면서 아래로 스위핑 or y 위치를 확인하면서 아래로 스위핑
-> x 기준으로 정렬한 좌표와, y 기준으로 정렬한 좌표가 필요...
한번 본 원소는 다시 보지 않게 만든다면 O(2N) 이상 탐색하지 않을듯..
2. set에 pair를 넣었을 때 사용하기 위한 테크닉
-> 좌표를 찾고 싶을 때 의미없는 값을 넣어서 찾기

*/
void solve()
{
    int a, b, n, m;
    cin >> a >> b >> n >> m;
    int xUpperLimit = a + 1, yUpperLimit = b + 1, xLowerLimit = 0, YLowerLimit = 0;
    set<pair<int, int>> x, y;
    for (int i = 0; i < n; i++)
    {
        int xx, yy;
        cin >> xx >> yy;
        x.insert({xx, yy});
        y.insert({yy, xx});
    }
    vector<int> ans(2, 0);
    for (int i = 0; i < m; i++)
    {
        char dir;
        int mag;
        cin >> dir >> mag;
        if (dir == 'D')
        {
            auto iter = x.lower_bound({xUpperLimit - mag, 0});
            for (; iter != x.end();)
            {

                if (iter->second < yUpperLimit && iter->second > YLowerLimit)
                    ans[i % 2]++;
                iter = x.erase(iter);
            }
            xUpperLimit -= mag;
        }
        if (dir == 'U')
        {
            auto iter = x.begin();
            for (; iter != x.end() && iter->first <= xLowerLimit + mag;)
            {
                if (iter->second < yUpperLimit && iter->second > YLowerLimit)
                    ans[i % 2]++;
                iter = x.erase(iter);
            }
            xLowerLimit += mag;
        }
        if (dir == 'R')
        {
            auto iter = y.upper_bound({yUpperLimit - mag, 0});
            for (; iter != y.end();)
            {
                if (iter->second < xUpperLimit && iter->second > xLowerLimit)
                    ans[i % 2]++;
                iter = y.erase(iter);
            }
            yUpperLimit -= mag;
        }
        if (dir == 'L')
        {
            auto iter = y.begin();
            for (; iter != y.end() && iter->first <= YLowerLimit + mag;)
            {
                if (iter->second < xUpperLimit && iter->second > xLowerLimit)
                    ans[i % 2]++;
                iter = y.erase(iter);
            }
            YLowerLimit += mag;
        }
    }
    for (auto i : ans)
    {
        cout << i << ' ';
    }
    cout << '\n';
}

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
