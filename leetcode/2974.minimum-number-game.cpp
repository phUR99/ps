/*
 * @lc app=leetcode id=2974 lang=cpp
 *
 * [2974] Minimum Number Game
 */

// @lc code=start
class Solution
{
public:
    vector<int> numberGame(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i += 2)
        {
            swap(nums[i], nums[i + 1]);
        }
        return nums;
    }
};
// @lc code=end
