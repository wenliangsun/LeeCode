#include <bits/stdc++.h>

#include "ListNode.h"

using namespace std;

/**
 * 题目203：移除链表元素
 */

class Solution {
   public:
    /**
     * 快慢指针
     */
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = head;
        while (cur) {
            if (cur->val == val) {
                pre->next = cur->next;
                cur = cur->next;
            } else {
                cur = cur->next;
                pre = pre->next;
            }
        }
        return dummy->next;
    }
};