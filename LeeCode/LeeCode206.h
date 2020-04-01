#include "ListNode.h"

/**
 * 题目206：翻转链表
 */
class LeeCode206 {
   public:
    /**
     * 思路：递归法
     * 时间复杂度：O(N)
     * 空间复杂度：O(N)
     */
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }

    /**
     * 思路：迭代法
     * 时间复杂度：O(N)
     * 空间复杂度：O(1)
     */
    ListNode* reverseList2(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};