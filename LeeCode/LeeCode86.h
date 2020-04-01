#include "ListNode.h"

/**
 * 题目86：分隔链表
 */
class LeeCode86 {
   public:
    /**
     * 思路：根据x值将链表拆分成两个链表，
     * 一个链表中的结点都是小于x的，另一个链表中的结点都是大于x的
     * 然后将这两个链表拼接起来
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     */
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* smallHead = new ListNode(-1);  // 小于x的链表
        ListNode* bigHead = new ListNode(-1);    // 大于x的链表
        ListNode* pSmall = smallHead;            // 小于x的链表的指针
        ListNode* pBig = bigHead;                // 大于x的链表的指针
        while (head != nullptr) {
            // 拆分链表
            if (head->val < x) {
                pSmall->next = head;
                pSmall = pSmall->next;
                head = head->next;
            } else {
                pBig->next = head;
                pBig = pBig->next;
                head = head->next;
            }
        }
        // 拼接链表
        if (pBig == bigHead) {
            return smallHead->next;
        } else if (pSmall == smallHead) {
            return bigHead->next;
        } else {
            pSmall->next = bigHead->next;
            pBig->next = nullptr;  // 注意这儿需要设置为null
            return smallHead->next;
        }
    }
};
