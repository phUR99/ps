/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * [389] Find the Difference
 */

// @lc code=start
class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        vector<int> alphabet(26, 0);
        for (auto c : t)
        {
            alphabet[c - 'a']++;
        }
        for (auto c : s)
        {
            alphabet[c - 'a']--;
        }

        int i = 0;
        for (; i < 26; i++)
        {
            if (alphabet[i])
                break;
        }
        return 'a' + i;
    }
};
// @lc code=end
