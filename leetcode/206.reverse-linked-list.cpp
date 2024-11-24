/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    queue<int> q;
    void dfs(ListNode *head)
    {
        if (head == nullptr)
            return;
        q.push(head->val);
        dfs(head->next);
        head->val = q.front();
        q.pop();
    }

    ListNode *reverseList(ListNode *head)
    {
        dfs(head);
        return head;
    }
};
// @lc code=end
