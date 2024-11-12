/*
 * @lc app=leetcode id=3211 lang=cpp
 *
 * [3211] Generate Binary Strings Without Adjacent Zeros
 */

// @lc code=start
class Solution
{
public:
    int s;
    void makeValidString(int idx, string str, vector<string> &ret)
    {
        if (idx == s)
        {
            ret.push_back(str);
            return;
        }
        if (idx == 0 || str[idx - 1] == '1')
            makeValidString(idx + 1, str + '0', ret);
        makeValidString(idx + 1, str + '1', ret);
    }
    vector<string> validStrings(int n)
    {
        vector<string> ret;
        s = n;
        makeValidString(0, "", ret);
        return ret;
    }
};
// @lc code=end
