/*
 * @lc app=leetcode id=884 lang=cpp
 *
 * [884] Uncommon Words from Two Sentences
 */

// @lc code=start
class Solution
{
public:
    void parsing(string &s, map<string, int> &dict)
    {
        int cur = 0;
        int pos;
        s += " ";
        while ((pos = s.find(" ", cur)) != string::npos)
        {
            int len = pos - cur;
            string temp = s.substr(cur, len);
            dict[temp]++;
            cur = pos + 1;
        }
    }
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        vector<string> ret;
        map<string, int> first, second;
        parsing(s1, first);
        parsing(s2, second);
        for (auto iter : first)
        {
            if (second.find(iter.first) == second.end() && first[iter.first] == 1)
                ret.push_back(iter.first);
        }
        for (auto iter : second)
        {
            if (first.find(iter.first) == first.end() && second[iter.first] == 1)
                ret.push_back(iter.first);
        }

        return ret;
    }
};
// @lc code=end
