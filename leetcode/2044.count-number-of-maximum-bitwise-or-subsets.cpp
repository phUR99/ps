/*
 * @lc app=leetcode id=2044 lang=cpp
 *
 * [2044] Count Number of Maximum Bitwise-OR Subsets
 */

// @lc code=start
class Solution
{
public:
    int n;
    vector<int> cache;
    int maxOR(int state, vector<int> &nums)
    {
        if (state == (1 << n) - 1)
            return 0;
        int &ret = cache[state];
        if (ret != -1)
            return ret;
        ret = 0;
        for (int i = 0; i < n; i++)
        {
            if (state & (1 << i))
                continue;
            int nxtState = state | (1 << i);
            ret = max(ret, nums[i] | maxOR(nxtState, nums));
        }
        return ret;
    }
    int countMaxOrSubsets(vector<int> &nums)
    {
        int ret = 0;
        n = nums.size();
        cache.resize((1 << n), -1);
        int M = maxOR(0, nums);
        for (int i = 0; i < (1 << n); i++)
        {
            ret += (cache[i] == M);
        }
        return ret;
    }
};
// @lc code=end
