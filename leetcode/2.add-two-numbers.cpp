/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    /*
    포인터를 반환하는 노드를 만드는 방법
    */
    ListNode *makeNode(ListNode *root, int val)
    {
        if (!root)
        {
            return root = new ListNode(val);
        }
        root->next = makeNode(root->next, val);
        return root;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int res = 0;
        // nullptr로 초기화를 해줘야 오류가 나지 않음
        ListNode *ret = nullptr;
        while (true)
        {
            if (!l1 && !l2 && !res)
                break;
            int cur = 0;
            if (l1)
            {
                cur += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                cur += l2->val;
                l2 = l2->next;
            }
            cur += res;
            res = cur / 10;
            ret = makeNode(ret, cur % 10);
        }
        return ret;
    }
};
// @lc code=end
