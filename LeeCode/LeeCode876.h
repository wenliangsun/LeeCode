#include "ListNode.h"

/**
 * 题目876：链表的中间结点
 */
class LeeCode876 {
   public:
    /**
     * 思路：快慢指针法
     */
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};