/*
 * @lc app=leetcode id=2798 lang=cpp
 *
 * [2798] Number of Employees Who Met the Target
 */

// @lc code=start
class Solution
{
public:
    int numberOfEmployeesWhoMetTarget(vector<int> &hours, int target)
    {
        int ret = 0;
        for (auto &hour : hours)
        {
            ret += (hour >= target);
        }
        return ret;
    }
};
// @lc code=end
