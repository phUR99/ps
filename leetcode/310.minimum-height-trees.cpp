/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */

// @lc code=start
class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 1)
            return {0};

        vector<vector<int>> adj(n);
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> q;
        vector<int> degree(n, 0);
        for (int i = 0; i < n; i++)
        {
            degree[i] = adj[i].size();
            if (degree[i] == 1)
            {
                q.push(i);
            }
        }

        while (n > 2)
        {
            int size = q.size();
            n -= size;
            for (int i = 0; i < size; i++)
            {
                int node = q.front();
                q.pop();
                for (int neighbor : adj[node])
                {
                    if (--degree[neighbor] == 1)
                    {
                        q.push(neighbor);
                    }
                }
            }
        }

        vector<int> result;
        while (!q.empty())
        {
            result.push_back(q.front());
            q.pop();
        }

        return result;
    }
};

// @lc code=end
