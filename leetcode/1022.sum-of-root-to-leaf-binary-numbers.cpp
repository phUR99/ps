/*
 * @lc app=leetcode id=1022 lang=cpp
 *
 * [1022] Sum of Root To Leaf Binary Numbers
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
    int dfs(TreeNode *here, int current)
    {
        if (here == nullptr)
            return 0;
        current <<= 1;
        current += here->val;
        if (here->left == nullptr && here->right == nullptr)
            return current;
        return dfs(here->left, current) + dfs(here->right, current);
    }
    int sumRootToLeaf(TreeNode *root)
    {
        return dfs(root, 0);
    }
};
// @lc code=end
