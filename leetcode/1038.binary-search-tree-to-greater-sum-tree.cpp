/*
 * @lc app=leetcode id=1038 lang=cpp
 *
 * [1038] Binary Search Tree to Greater Sum Tree
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
    // 굳이 새로운 트리를 만들 필요 없이 기존의 트리를 수정하는 방향으로
    void dfs(TreeNode *root, int &sum)
    {
        if (!root)
            return;
        dfs(root->right, sum);
        root->val += sum;
        sum = root->val;
        dfs(root->left, sum);
    }
    TreeNode *bstToGst(TreeNode *root)
    {
        int sum = 0;
        dfs(root, sum);
        return root;
    }
};
// @lc code=end
