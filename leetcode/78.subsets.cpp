/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution
{
public:
    int n;
    vector<bool> visited;
    void solve(int state, vector<vector<int>> &ret, vector<int> &nums)
    {
        visited[state] = 1;
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            if (state & (1 << i))
                temp.push_back(nums[i]);
        }
        ret.push_back(temp);
        for (int i = 0; i < n; i++)
        {
            if (state & (1 << i))
                continue;
            int nxtState = (state | (1 << i));
            if (visited[nxtState])
                continue;
            solve(nxtState, ret, nums);
        }
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ret;
        n = nums.size();
        visited.resize(1 << n, 0);

        solve(0, ret, nums);
        return ret;
    }
};
// @lc code=end
