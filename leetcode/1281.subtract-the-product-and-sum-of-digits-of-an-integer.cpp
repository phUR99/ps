/*
 * @lc app=leetcode id=1281 lang=cpp
 *
 * [1281] Subtract the Product and Sum of Digits of an Integer
 */

// @lc code=start
class Solution
{
public:
    int subtractProductAndSum(int n)
    {
        int product = 1;
        int sum = 0;
        string str = to_string(n);
        for (auto &c : str)
        {
            int num = c - '0';
            product *= num;
            sum += num;
        }
        return product - sum;
    }
};
// @lc code=end
