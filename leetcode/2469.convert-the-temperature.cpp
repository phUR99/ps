/*
 * @lc app=leetcode id=2469 lang=cpp
 *
 * [2469] Convert the Temperature
 */

// @lc code=start
#ifndef ONLINE_JUDGE
#include <bits/stdc++.h>
using namespace std;
#endif

class Solution
{
public:
    vector<double> convertTemperature(double celsius)
    {
        vector<double> ret(2);
        ret[0] = celsius + 273.15;
        ret[1] = celsius * 1.80 + 32.00;
        return ret;
    }
};
// @lc code=end
