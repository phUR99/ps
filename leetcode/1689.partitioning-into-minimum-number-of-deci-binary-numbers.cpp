/*
 * @lc app=leetcode id=1689 lang=cpp
 *
 * [1689] Partitioning Into Minimum Number Of Deci-Binary Numbers
 */

// @lc code=start
class Solution
{
public:
    int minPartitions(string n)
    {
        int ret = 0;
        for (auto s : n)
        {
            ret = max(ret, s - '0');
        }
        return ret;
    }
};
// @lc code=end
