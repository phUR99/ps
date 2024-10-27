/*
 * @lc app=leetcode id=1929 lang=cpp
 *
 * [1929] Concatenation of Array
 */

// @lc code=start
#ifndef ONLINE_JUDGE
#include <bits/stdc++.h>
using namespace std;
#endif

class Solution
{
public:
    vector<int> getConcatenation(vector<int> &nums)
    {
        vector<int> ans = nums;
        for (auto i : nums)
        {
            ans.push_back(i);
        }
        return ans;
    }
};
// @lc code=end
