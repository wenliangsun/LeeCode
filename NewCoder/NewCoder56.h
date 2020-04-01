#include "ListNode.h"

/**
 * 题目56：删除链表中重复的结点
 * 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
 * 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
 *
 */
class NewCoder56 {
   public:
    ListNode* deleteDuplication(ListNode* pHead) {
        if (pHead == nullptr) {
            return nullptr;
        }
        if (pHead->next == nullptr) {
            return pHead;
        }
        ListNode* preIndex = nullptr;
        ListNode* curIndex = pHead;
        ListNode* posIndex = nullptr;
        while (curIndex != nullptr) {
            if (curIndex->next != nullptr &&
                curIndex->val == curIndex->next->val) {
                posIndex = curIndex->next;
                while (posIndex != nullptr && posIndex->next != nullptr &&
                       posIndex->val == posIndex->next->val) {
                    posIndex = posIndex->next;
                }
                if (curIndex == pHead) {
                    pHead = posIndex->next;
                } else {
                    preIndex->next = posIndex->next;
                }
                curIndex = posIndex->next;
            } else {
                preIndex = curIndex;
                curIndex = curIndex->next;
            }
        }
        return pHead;
    }
};
