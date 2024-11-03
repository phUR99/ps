/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int ret = 0;
        int l = 0;
        int r = 0;
        int n = s.size();
        unordered_map<char, int> hashMap;
        while (l < n)
        {
            while (r < n && hashMap.find(s[r]) == hashMap.end())
            {
                hashMap[s[r++]]++;
            }
            ret = max(ret, r - l);
            hashMap[s[l]]--;
            if (hashMap[s[l]] == 0)
                hashMap.erase(s[l]);
            l++;
        }
        return ret;
    }
};
// @lc code=end
