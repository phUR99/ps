/*
 * @lc app=leetcode id=2810 lang=cpp
 *
 * [2810] Faulty Keyboard
 */

// @lc code=start
class Solution
{
public:
    string finalString(string s)
    {
        string ret;
        for (auto &ss : s)
        {
            if (ss == 'i')
                reverse(ret.begin(), ret.end());
            else
                ret += ss;
        }
        return ret;
    }
};
// @lc code=end
