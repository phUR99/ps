/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution
{
public:
    int hammingWeight(int n)
    {
        int ret = 0;
        for (int i = 0; i < 32; i++)
        {
            ret += ((n >> i) & 1);
        }
        return ret;
    }
};
// @lc code=end
