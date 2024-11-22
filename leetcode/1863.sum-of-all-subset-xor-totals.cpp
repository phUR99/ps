/*
 * @lc app=leetcode id=1863 lang=cpp
 *
 * [1863] Sum of All Subset XOR Totals
 */

// @lc code=start
class Solution
{
public:
    int n;
    vector<int> cache;
    void solve(int state, vector<int> &nums)
    {
        if (state == (1 << n) - 1)
            return;
        for (int i = 0; i < n; i++)
        {
            if (state & (1 << i))
                continue;
            int nxtState = (state | (1 << i));
            if (cache[nxtState] != -1)
                continue;
            cache[nxtState] = cache[state] ^ nums[i];
            solve(nxtState, nums);
        }
    }

    int subsetXORSum(vector<int> &nums)
    {
        int ret = 0;
        n = nums.size();
        cache.resize(1 << n, -1);
        cache[0] = 0;
        solve(0, nums);
        for (int i = 0; i < (1 << n); i++)
        {
            if (cache[i] != -1)
                ret += cache[i];
        }

        return ret;
    }
};
// @lc code=end
