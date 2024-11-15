/*
 * @lc app=leetcode id=1672 lang=cpp
 *
 * [1672] Richest Customer Wealth
 */

// @lc code=start
class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int ret = 0;
        for (auto &account : accounts)
        {
            int sum = accumulate(account.begin(), account.end(), 0);
            ret = max(ret, sum);
        }
        return ret;
    }
};
// @lc code=end
