/*
 * @lc app=leetcode id=1512 lang=cpp
 *
 * [1512] Number of Good Pairs
 */

// @lc code=start
class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        int ret = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                ret += (nums[i] == nums[j]);
            }
        }
        return ret;
    }
};
// @lc code=end
