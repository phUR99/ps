/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> adj;
    set<pair<int, int>> ans;
    vector<int> discovered;
    int counter = 0;

    int dfs(int here, int parent)
    {
        discovered[here] = counter++;
        int ret = discovered[here];
        for (auto there : adj[here])
        {
            if (there == parent)
                continue;
            if (discovered[there] == -1)
            {
                int subTree = dfs(there, here);
                if (subTree > ret)
                    ans.insert({min(here, there), max(here, there)});

                ret = min(ret, subTree);
            }
            else
                ret = min(ret, discovered[there]);
        }
        return ret;
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        vector<int> ret;
        int n = edges.size();
        adj.resize(n + 1);
        discovered.resize(n + 1, -1);
        for (auto i : edges)
        {
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 1; i <= n; i++)
        {
            if (discovered[i] == -1)
                dfs(i, 0);
        }
        reverse(edges.begin(), edges.end());
        for (auto cur : edges)
        {
            int u = min(cur[0], cur[1]);
            int v = max(cur[0], cur[1]);
            if (ans.find({u, v}) == ans.end())
            {
                ret.push_back(u);
                ret.push_back(v);
                break;
            }
        }

        return ret;
    }
};
// @lc code=end
