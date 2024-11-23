/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        long long ret = 1;
        if (x == 0)
            return 0;
        for (; ret * ret <= x; ret++)
        {
            if ((ret + 1) * (ret + 1) > x)
                break;
        }
        return ret;
    }
};
// @lc code=end
