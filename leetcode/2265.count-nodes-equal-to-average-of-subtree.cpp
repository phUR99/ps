/*
 * @lc app=leetcode id=2265 lang=cpp
 *
 * [2265] Count Nodes Equal to Average of Subtree
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
    int valueSameAverage = 0;
    pair<int, int> calculate(TreeNode *root)
    {
        pair<int, int> ret = {root->val, 1};
        if (root->left != nullptr)
        {
            pair<int, int> tmp = calculate(root->left);
            ret.first += tmp.first;
            ret.second += tmp.second;
        }
        if (root->right != nullptr)
        {
            pair<int, int> tmp = calculate(root->right);
            ret.first += tmp.first;
            ret.second += tmp.second;
        }
        if (ret.first / ret.second == root->val)
            valueSameAverage++;
        return ret;
    }

    int averageOfSubtree(TreeNode *root)
    {
        calculate(root);
        return valueSameAverage;
    }
};
// @lc code=end
