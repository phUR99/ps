/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
    void dfs(TreeNode *here, vector<string> &ret, vector<int> &arr)
    {
        if (here == nullptr)
            return;
        arr.push_back(here->val);
        bool isLeaf = (here->left == nullptr) && (here->right == nullptr);
        if (isLeaf)
        {
            string tmp;
            for (int i = 0; i < arr.size(); i++)
            {
                tmp += to_string(arr[i]);
                if (i != arr.size() - 1)
                    tmp += "->";
            }
            ret.push_back(tmp);
        }
        dfs(here->left, ret, arr);
        dfs(here->right, ret, arr);
        arr.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ret;
        vector<int> arr;
        dfs(root, ret, arr);
        return ret;
    }
};
// @lc code=end
