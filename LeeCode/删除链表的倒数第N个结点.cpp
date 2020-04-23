#include "ListNode.h"

/**
 * 题目19：删除链表的倒数第N个结点
 */
class LeeCode19 {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* newHead = new ListNode(0);  // 给头结点新添一个结点
        newHead->next = head;
        ListNode* p1 = newHead;
        ListNode* p2 = newHead;
        for (int i = 0; i <= n; i++) {  // 先走n步
            if (p2 != nullptr) {
                p2 = p2->next;
            } else {
                return nullptr;
            }
        }
        while (p2 != nullptr) {
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = p1->next->next;
        return newHead->next;
    }
};