/*
 * @lc app=leetcode id=3280 lang=cpp
 *
 * [3280] Convert Date to Binary
 */

// @lc code=start
class Solution
{
public:
    string convertDateToBinary(string date)
    {
        date += '-';
        int cur = 0;
        int pos;
        vector<string> temp;
        while ((pos = date.find('-', cur)) != string::npos)
        {
            int len = pos - cur;
            string tmp = date.substr(cur, len);
            temp.push_back(tmp);
            cur = pos + 1;
        }
        string ret;
        for (int i = 0; i < temp.size(); i++)
        {
            int pow = 1;
            string tmp;
            while (pow <= stoi(temp[i]))
            {
                tmp += to_string((pow & stoi(temp[i])) != 0);
                pow *= 2;
            }
            reverse(tmp.begin(), tmp.end());
            ret += tmp;
            if (i != temp.size() - 1)
                ret += '-';
        }

        return ret;
    }
};
// @lc code=end
