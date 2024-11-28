/*
 * @lc app=leetcode id=1678 lang=cpp
 *
 * [1678] Goal Parser Interpretation
 */

// @lc code=start
class Solution
{
public:
    string interpret(string command)
    {
        string ret;
        for (int i = 0; i < command.size(); i++)
        {
            char s = command[i];
            if (s == 'G')
                ret += s;
            else if (s == '(')
            {
                char n = command[i + 1];
                if (n == ')')
                    ret += 'o';
                else
                    ret += "al";
            }
        }
        return ret;
    }
};
// @lc code=end
