/*
 * @lc app=leetcode id=3110 lang=cpp
 *
 * [3110] Score of a String
 */

// @lc code=start
#ifndef ONLINE_JUDGE
#include <bits/stdc++.h>
using namespace std;
#endif

class Solution
{
public:
    int scoreOfString(string s)
    {
        int ret = 0;
        int l = s.size();
        for (int i = 1; i < l; i++)
        {
            ret += abs(s[i] - s[i - 1]);
        }
        return ret;
    }
};
// @lc code=end
