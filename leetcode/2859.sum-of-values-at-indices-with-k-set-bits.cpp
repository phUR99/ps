/*
 * @lc app=leetcode id=2859 lang=cpp
 *
 * [2859] Sum of Values at Indices With K Set Bits
 */

// @lc code=start
class Solution
{
public:
    int sumIndicesWithKSetBits(vector<int> &nums, int k)
    {
        int ret = 0;
        for (int idx = 0; idx < nums.size(); idx++)
        {
            int cnt = 0;
            for (int i = 0; i < 32; i++)
            {
                if (idx & (1 << i))
                    cnt++;
            }
            if (cnt == k)
                ret += nums[idx];
        }
        return ret;
    }
};
// @lc code=end
