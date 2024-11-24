/*
 * @lc app=leetcode id=1365 lang=cpp
 *
 * [1365] How Many Numbers Are Smaller Than the Current Number
 */

// @lc code=start
class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        vector<int> ret;
        for (auto &i : nums)
        {
            int cnt = 0;
            for (auto &j : nums)
            {
                if (j < i)
                    cnt++;
            }
            ret.push_back(cnt);
        }
        return ret;
    }
};
// @lc code=end
