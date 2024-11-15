/*
 * @lc app=leetcode id=2220 lang=cpp
 *
 * [2220] Minimum Bit Flips to Convert Number
 */

// @lc code=start

class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        int xorStart = start ^ goal;
        int ret = 0;
        for (int i = 0; i < 32; i++)
        {
            // 연산자 우선순위 신경쓰기
            ret += (xorStart & (1 << i)) != 0;
        }
        return ret;
    }
};
// @lc code=end
