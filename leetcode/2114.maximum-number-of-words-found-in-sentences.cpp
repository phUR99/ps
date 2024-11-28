/*
 * @lc app=leetcode id=2114 lang=cpp
 *
 * [2114] Maximum Number of Words Found in Sentences
 */

// @lc code=start
class Solution
{
public:
    int mostWordsFound(vector<string> &sentences)
    {
        int ret = 0;
        for (auto &sentence : sentences)
        {
            int cnt = 0;
            int cur = 0;
            int pos;
            while ((pos = sentence.find(' ', cur)) != string::npos)
            {
                cnt++;
                cur = pos + 1;
            }
            ret = max(ret, cnt + 1);
        }
        return ret;
    }
};
// @lc code=end
