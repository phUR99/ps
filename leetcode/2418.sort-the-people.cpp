/*
 * @lc app=leetcode id=2418 lang=cpp
 *
 * [2418] Sort the People
 */

// @lc code=start
class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        vector<pair<int, string>> arr;
        vector<string> ret;
        int n = names.size();
        for (int i = 0; i < n; i++)
        {
            arr.push_back({heights[i], names[i]});
        }
        sort(arr.begin(), arr.end(), greater<>());
        for (auto &i : arr)
        {
            ret.push_back(i.second);
        }
        return ret;
    }
};
// @lc code=end
