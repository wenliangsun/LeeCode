#include "ListNode.h"

/**
 * 题目2：两数相加
 * 给出两个非空的链表用来表示两个非负的整数。
 * 其中，它们各自的位数是按照逆序的方式存储的，并且它们的每个节点只能存储一位数字。
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 */
class LeeCode02 {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        ListNode* newHead = new ListNode(0); // 新头结点
        ListNode* pHead = newHead; 
        int carry = 0; // 进位
        while (l1 != nullptr || l2 != nullptr) {
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            sum = sum % 10;
            pHead->next = new ListNode(sum);
            pHead = pHead->next;
            if (l1 != nullptr) {
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }
        if (carry > 0) { // 如果加完了，还有进位，就新建结点
            pHead->next = new ListNode(carry);
        }
        return newHead->next;
    }
};