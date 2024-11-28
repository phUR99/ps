/*
 * @lc app=leetcode id=2325 lang=cpp
 *
 * [2325] Decode the Message
 */

// @lc code=start
class Solution
{
public:
    string decodeMessage(string key, string message)
    {

        unordered_map<char, int> dict;
        int cnt = 0;
        for (char &c : key)
        {
            if (c == ' ')
                continue;
            if (dict.count(c))
                continue;
            dict[c] = cnt++;
        }

        for (char &c : message)
        {
            if (c == ' ')
                continue;
            c = dict[c] + 'a';
        }
        return message;
    }
};
// @lc code=end
