/*
 * @lc app=leetcode id=1684 lang=cpp
 *
 * [1684] Count the Number of Consistent Strings
 */

// @lc code=start
class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        int ret = 0;
        for (auto &word : words)
        {
            for (auto c : word)
            {
                // string::npos 확인
                if (allowed.find(c) == string::npos)
                {
                    ret--;
                    break;
                }
            }
            ret++;
        }
        return ret;
    }
};
// @lc code=end
