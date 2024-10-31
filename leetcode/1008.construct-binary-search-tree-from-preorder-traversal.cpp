/*
 * @lc app=leetcode id=1008 lang=cpp
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
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
/*
참조자로 줘야하는 이유
주소를 복사 (cur과 root는 다름)
cur에 새로운 노드를 할당하고 함수를 종료해도 cur과 root는 다르기 때문에 root는 여전히 nullptr
수정 방법 1 : 참조자로 root를 줘서 root를 직접 변형하기
수정 방법 2 : 포인터로 주되, 반환값을 포인터로 해서 root값 수정하기

*/
class Solution
{
public:
    void makeTree(TreeNode *(&cur), int val)
    {
        if (!cur)
        {
            cur = new TreeNode(val);
            return;
        }
        if (val > cur->val)
            makeTree(cur->right, val);
        else
            makeTree(cur->left, val);
    }

    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        TreeNode *root = nullptr;
        int n = preorder.size();
        for (int i = 0; i < n; i++)
        {
            makeTree(root, preorder[i]);
        }
        return root;
    }
};
// @lc code=end
