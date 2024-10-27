/*
 * @lc app=leetcode id=1920 lang=cpp
 *
 * [1920] Build Array from Permutation
 */

// @lc code=start
#ifndef ONLINE_JUDGE
#include <bits/stdc++.h>
using namespace std;
#endif

class Solution
{
public:
    vector<int> buildArray(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            // encoding & decoding (using no elements >= n)
            nums[i] += n * (nums[nums[i]] % n);
        }
        for (int i = 0; i < n; i++)
        {
            nums[i] = nums[i] / n;
        }
        return nums;
    }
};
// @lc code=end
