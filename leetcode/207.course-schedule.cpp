/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {

        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (const auto &pre : prerequisites)
        {
            int a = pre[0];
            int b = pre[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            int here = q.front();
            q.pop();
            for (const int &there : adj[here])
            {
                indegree[there]--;
                if (indegree[there] == 0)
                    q.push(there);
            }
        }
        return *max_element(indegree.begin(), indegree.end()) == 0;
    }
};
// @lc code=end
