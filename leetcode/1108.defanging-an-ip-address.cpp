/*
 * @lc app=leetcode id=1108 lang=cpp
 *
 * [1108] Defanging an IP Address
 */

// @lc code=start

#ifndef ONLINE_JUDGE
#include <bits/stdc++.h>
using namespace std;
#endif

class Solution
{
public:
    string defangIPaddr(string address)
    {
        string ret = "";
        for (auto &s : address)
        {
            if (s == '.')
                ret += "[.]";
            else
                ret += s;
        }
        return ret;
    }
};
// @lc code=end
