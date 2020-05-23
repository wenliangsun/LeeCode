#include "ListNode.h"

/**
 * 题目141：环形链表
 */
class LeeCode141 {
   public:
    /**
     * 思路：快慢指针
     * 快指针每次走两步，慢指针每次走一步，如果有环的话，快慢指针会相遇
     */
    bool hasCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};