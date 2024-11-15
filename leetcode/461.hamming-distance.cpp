/*
 * @lc app=leetcode id=461 lang=cpp
 *
 * [461] Hamming Distance
 */

// @lc code=start
class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int ret = 0;
        for (int i = 0; i < 32; i++)
        {
            int xBit = x & (1 << i);
            int yBit = y & (1 << i);
            ret += (xBit != yBit);
        }
        return ret;
    }
};
// @lc code=end
