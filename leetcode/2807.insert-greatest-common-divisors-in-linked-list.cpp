/*
 * @lc app=leetcode id=2807 lang=cpp
 *
 * [2807] Insert Greatest Common Divisors in Linked List
 */

// @lc code=start
#ifndef ONLINE_JUDGE
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#endif

class Solution
{
public:
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        ListNode *cur = head;
        ListNode *nxt = head->next;
        while (nxt != nullptr)
        {
            ListNode *tmp = new ListNode;
            tmp->val = __gcd(cur->val, nxt->val);
            tmp->next = nxt;
            cur->next = tmp;
            cur = nxt;
            nxt = cur->next;
        }
        return head;
    }
};
// @lc code=end
