/*
 * @lc app=leetcode id=2610 lang=cpp
 *
 * [2610] Convert an Array Into a 2D Array With Conditions
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        vector<vector<int>> ret;
        int n = nums.size();
        vector<int> group(n, 0);
        vector<int> idx(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            group[i] = idx[nums[i]]++;
        }
        int M = *max_element(idx.begin(), idx.end());
        ret.resize(M);
        for (int i = 0; i < n; i++)
        {
            ret[group[i]].push_back(nums[i]);
        }

        return ret;
    }
};
// @lc code=end
