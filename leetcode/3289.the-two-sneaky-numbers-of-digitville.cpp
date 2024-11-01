/*
 * @lc app=leetcode id=3289 lang=cpp
 *
 * [3289] The Two Sneaky Numbers of Digitville
 */

// @lc code=start
class Solution
{
public:
    vector<int> getSneakyNumbers(vector<int> &nums)
    {
        vector<int> ret;
        set<int> s;
        for (auto &i : nums)
        {
            if (s.find(i) != s.end())
                ret.push_back(i);
            s.insert(i);
        }
        return ret;
    }
};
// @lc code=end
