#include "ListNode.h"

/**
 * 题目24：两两交换链表中的结点
 */
class LeeCode24 {
   public:
    /**
     * 思路：采用递归
     */
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* node = head->next;  // 记录下一个结点
        // 第一个结点的next指向之后交换的结点
        head->next = swapPairs(node->next);
        node->next = head;  // 下一个结点的next指向前一个结点
        return node;
    }

    /**
     * 思路：非递归方法
     */
    ListNode* swapPairs02(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* pre = new ListNode(0);
        pre->next = head;
        ListNode* p = pre;
        while (p->next != nullptr && p->next->next != nullptr) {
            // 注意这儿的交换
            ListNode* start = p->next;
            ListNode* end = p->next->next;
            p->next = end;
            start->next = end->next;
            end->next = start;
            p = start;
        }
        return pre->next;
    }
};