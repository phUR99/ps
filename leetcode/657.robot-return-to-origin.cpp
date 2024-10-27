/*
 * @lc app=leetcode id=657 lang=cpp
 *
 * [657] Robot Return to Origin
 */
#ifndef ONLINE_JUDGE
#include <bits/stdc++.h>
using namespace std;
#endif
// @lc code=start
class Solution
{
public:
    bool judgeCircle(string moves)
    {
        string dir = "UDLR";
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        int x = 0, y = 0;
        for (char s : moves)
        {
            int d = dir.find(s);
            x += dx[d];
            y += dy[d];
        }
        return x == 0 && y == 0;
    }
};
// @lc code=end
