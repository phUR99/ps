/*
 * @lc app=leetcode id=1791 lang=cpp
 *
 * [1791] Find Center of Star Graph
 */

// @lc code=start
class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<bool> indegree(n + 2, 0);
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            if (indegree[u])
                return u;
            if (indegree[v])
                return v;
            indegree[u] = indegree[v] = 1;
        }
        return 0;
    }
};
// @lc code=end
