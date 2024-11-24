/*
 * @lc app=leetcode id=1302 lang=cpp
 *
 * [1302] Deepest Leaves Sum
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
    map<int, int> depthBySum;
    void dfs(TreeNode *root, int depth)
    {
        if (root == nullptr)
            return;
        depthBySum[depth] += root->val;
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }
    int deepestLeavesSum(TreeNode *root)
    {
        dfs(root, 0);
        auto iter = prev(depthBySum.end());
        return iter->second;
    }
};
// @lc code=end
