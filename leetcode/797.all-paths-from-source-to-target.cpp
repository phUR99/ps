/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    void dfs(int start, int end, vector<vector<int>> &adj)
    {
        tmp.push_back(start);
        if (start == end)
        {
            ans.push_back(tmp);
        }
        for (int there : adj[start])
        {
            dfs(there, end, adj);
        }
        tmp.pop_back();
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        dfs(0, graph.size() - 1, graph);
        return ans;
    }
};
// @lc code=end
