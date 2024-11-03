/*
 * @lc app=leetcode id=1470 lang=cpp
 *
 * [1470] Shuffle the Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        vector<int> ret(2 * n);
        for (int i = 0; i < n; i++)
        {
            ret[2 * i] = nums[i];
            ret[2 * i + 1] = nums[i + n];
        }
        return ret;
    }
};
// @lc code=end
