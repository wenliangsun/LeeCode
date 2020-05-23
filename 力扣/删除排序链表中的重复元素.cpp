#include "ListNode.h"

/**
 * 题目83：删除排序链表中的重复元素
 */
class LeeCode83 {
   public:
    /**
     * 思路：直接法
     */
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* p = head;
        while (p->next != nullptr) {
            if (p->val == p->next->val) {
                p->next = p->next->next;
            } else {
                p = p->next;
            }
        }
        return head;
    }
};