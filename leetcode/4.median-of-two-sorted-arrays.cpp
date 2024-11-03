/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        double ret = 0;
        vector<int> arr(n + m);
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), arr.begin());
        if ((n + m) % 2)
        {
            ret = arr[(n + m) / 2];
        }
        else
        {
            ret = arr[(n + m) / 2] + arr[(n + m) / 2 - 1];
            ret /= 2;
        }
        return ret;
    }
};
// @lc code=end
