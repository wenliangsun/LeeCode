#include <stack>

#include "ListNode.h"

using namespace std;

/**
 * 题目93：反转链表II
 * 一系列反转链表的操作：反转整个链表，反正前N个链表，反转某个区间的链表
 * 采用递归的方法
 */
class LeeCode92 {
   public:
    /**
     * 反转链表的某个区间[m,n]
     * 可以看做是将头结点向后移动m个结点，然后然转前n-m个结点
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == 1) {
            return reverseN(head, n);
        }
        head->next = reverseBetween(head->next, m - 1, n - 1);
        return head;
    }

    /**
     * 思路：借助栈
     */
    ListNode* reverseBetween2(ListNode* head, int m, int n) {
        if (head == nullptr) {
            return head;
        }
        ListNode* pNode = head;
        ListNode* newHead = new ListNode(-1);
        ListNode* pNew = newHead;
        stack<ListNode*> stk;
        int count = 0;
        while (pNode != nullptr) {
            count++;
            if (count >= m && count <= n) {
                stk.push(pNode);
                pNode = pNode->next;
                continue;
            }
            if (count > n && !stk.empty()) {
                while (!stk.empty()) {
                    pNew->next = stk.top();
                    stk.pop();
                    pNew = pNew->next;
                }
            } else {
                pNew->next = pNode;
                pNode = pNode->next;
                pNew = pNew->next;
            }
        }
        while (!stk.empty()) {
            pNew->next = stk.top();
            stk.pop();
            pNew = pNew->next;
        }
        return newHead->next;
    }

   private:
    /**
     * 反转整个链表
     */
    ListNode* successor;
    ListNode* reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
            ListNode* last = reverse(head->next);
            head->next->next = head;
            head->next = nullptr;
            return last;
        }
    }
    /**
     * 反转链表的前N的结点
     */
    ListNode* reverseN(ListNode* head, int n) {
        if (n == 1) {
            // 记录第n+1个节点
            successor = head->next;
            return head;
        }
        // 以 head->next 为起点，需要反转前 n - 1 个节点
        ListNode* last = reverseN(head->next, n - 1);
        head->next->next = head;
        // 让反转之后的 head 节点和后面的节点连起来
        head->next = successor;
        return last;
    }
};