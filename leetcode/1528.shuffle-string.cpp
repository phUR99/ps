/*
 * @lc app=leetcode id=1528 lang=cpp
 *
 * [1528] Shuffle String
 */

// @lc code=start
class Solution
{
public:
    string restoreString(string s, vector<int> &indices)
    {
        string ret;
        int n = s.size();
        vector<pair<int, char>> arr(n);
        for (int i = 0; i < n; i++)
        {
            arr[i].first = indices[i];
            arr[i].second = s[i];
        }
        sort(arr.begin(), arr.end());
        for (auto i : arr)
        {
            ret += i.second;
        }

        return ret;
    }
};
// @lc code=end
