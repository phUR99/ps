/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution
{
public:
    int reverse(int x)
    {
        bool plus = x > 0;
        string str(to_string(abs(x)));
        std::reverse(str.begin(), str.end());
        long long rx = stol(str);
        if (rx >= (1LL << 31) - 1)
            return 0;
        if (plus)
            return stoi(str);
        else
            return -stoi(str);
    }
};
// @lc code=end
