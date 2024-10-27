/*
 * @lc app=leetcode id=3190 lang=cpp
 *
 * [3190] Find Minimum Operations to Make All Elements Divisible by Three
 */

// @lc code=start
#ifndef ONLINE_JUDGE
#include <bits/stdc++.h>
using namespace std;
#endif

class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        int ret = 0;
        for (auto &i : nums)
        {
            // 0, 1, 2 -> 1, 2일 때만 체크
            if (i % 3 == 0)
                continue;
            ret++;
        }
        return ret;
    }
};
// @lc code=end
