#include "ListNode.h"

/**
 * 题目21：合并两个有序链表
 */
class LeeCode21 {
   public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        ListNode* newHead = new ListNode(0);
        ListNode* p = newHead;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                p->next = l1;
                p = p->next;
                l1 = l1->next;
            } else {
                p->next = l2;
                p = p->next;
                l2 = l2->next;
            }
        }
        while (l1) {
            p->next = l1;
            p = p->next;
            l1 = l1->next;
        }
        while (l2) {
            p->next = l2;
            p = p->next;
            l2 = l2->next;
        }
        return newHead->next;
    }
};