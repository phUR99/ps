/*
 * @lc app=leetcode id=3146 lang=cpp
 *
 * [3146] Permutation Difference between Two Strings
 */

// @lc code=start
class Solution
{
public:
    int findPermutationDifference(string s, string t)
    {
        int ret = 0;

        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            ret += abs((int)s.find(t[i]) - i);
        }

        return ret;
    }
};
// @lc code=end
