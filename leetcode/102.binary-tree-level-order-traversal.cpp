/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void dfs(TreeNode *root, int depth, vector<vector<int>> &adj)
    {
        if (root == nullptr)
            return;
        if (adj.size() <= depth)
            adj.push_back({});
        adj[depth].push_back(root->val);
        dfs(root->left, depth + 1, adj);
        dfs(root->right, depth + 1, adj);
    }

    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ret;
        dfs(root, 0, ret);
        return ret;
    }
};
// @lc code=end
