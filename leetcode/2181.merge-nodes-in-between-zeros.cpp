/*
 * @lc app=leetcode id=2181 lang=cpp
 *
 * [2181] Merge Nodes in Between Zeros
 */

// @lc code=start

class Solution
{
public:
    ListNode *mergeNodes(ListNode *head)
    {
        head = head->next;
        int sum = 0;
        ListNode *ret = new ListNode;
        ListNode *cur = ret;

        while (head != nullptr)
        {
            if (head->val == 0)
            {
                ListNode *tmp = new ListNode(sum);
                cur->next = tmp;
                cur = cur->next;
                sum = 0;
            }
            sum += head->val;
            head = head->next;
        }
        // 예외를 굳이 처리하는 것보다는 일관되게 만든 후에 더미 노드만 뛰어넘기
        return ret->next;
    }
};
// @lc code=end
