/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 */

// @lc code=start
class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r)
        {
            while (l < r && (nums[l] % 2 == 0))
            {
                l++;
            }
            while (l < r && (nums[r] % 2 == 1))
            {
                r--;
            }
            swap(nums[l], nums[r]);
        }
        return nums;
    }
};
// @lc code=end
