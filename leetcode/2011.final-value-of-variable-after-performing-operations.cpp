/*
 * @lc app=leetcode id=2011 lang=cpp
 *
 * [2011] Final Value of Variable After Performing Operations
 */

// @lc code=start
#ifndef ONLINE_JUDGE
#include <bits/stdc++.h>
using namespace std;
#endif

class Solution
{
public:
    int finalValueAfterOperations(vector<string> &operations)
    {
        int ret = 0;
        for (auto &str : operations)
        {
            if (str[1] == '+')
                ret++;
            else
                ret--;
        }
        return ret;
    }
};
// @lc code=end
