#include "ListNode.h"

/**
 * 题目82：删除排序链表中的重复元素II
 */
class LeeCode82 {
   public:
    /**
     * 思路：快慢指针
     */
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* pPreNode = head;  // 快指针
        ListNode* newHead = new ListNode(0);
        ListNode* pPosNode = newHead;  // 慢指针
        newHead->next = head;
        while (pPreNode->next != nullptr) {
            // 如果快指针和下一个指针不相同时，
            // 有两种情况: (1)快指针经历了重复结点，(2)没有经历重复结点
            if (pPreNode->val != pPreNode->next->val) {
                // 没有经历重复结点
                if (pPosNode->next == pPreNode) {
                    pPosNode = pPreNode;
                    // 经历了重复结点
                } else {
                    pPosNode->next = pPreNode->next;
                }
            }
            pPreNode = pPreNode->next;
        }
        // 判断结点是否都重复的情况，1->1->1->1->1->nullptr
        if (pPosNode->next != pPreNode) {
            pPosNode->next = pPreNode->next;
        }
        return newHead->next;
    }
};