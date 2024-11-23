/*
 * @lc app=leetcode id=1431 lang=cpp
 *
 * [1431] Kids With the Greatest Number of Candies
 */

// @lc code=start
class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        vector<bool> ret;
        for (auto &candy : candies)
        {
            bool isGreatest = true;
            for (int i = 0; i < candies.size(); i++)
            {
                if (candy + extraCandies < candies[i])
                {
                    isGreatest = false;
                    break;
                }
            }
            ret.push_back(isGreatest);
        }
        return ret;
    }
};
// @lc code=end
