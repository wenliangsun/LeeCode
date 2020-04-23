#include <stack>

#include "ListNode.h"

using namespace std;

/**
 * 题目25：K个一组翻转链表
 */
class LeeCode25 {
   public:
    /**
     * 思路：采用O(k)的临时栈
     *
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k <= 1) {
            return head;
        }
        ListNode* node = head;  // 链表指针
        ListNode* newHead = new ListNode(0);
        ListNode* newNode = newHead;  // 新链表指针
        while (node != nullptr) {
            int i = 0;
            stack<ListNode*> stk;  // 临时栈
            ListNode* temp = node;  // 记录当前结点，以防剩余结点不够k个
            for (; i < k; i++) {
                stk.push(node);
                if (node != nullptr) {  // 不是null入栈
                    node = node->next;
                } else {  // 否则，指针退回上一次初始位置，跳出循环
                    i = 0;
                    node = temp;
                    break;
                }
            }
            while (i == k && !stk.empty()) {  // 如果够k个结点，出栈
                newNode->next = stk.top();
                newNode = newNode->next;
                stk.pop();
            }
            newNode->next = node;
            if (i == 0 && node != nullptr) {  // 否则把node之后连接起来
                node = node->next;
                newNode = newNode->next;
            }
        }
        return newHead->next;
    }

    /**
     * 递归法
     * 翻转前k个之后，翻转后面的链表变成了子问题
     */
    ListNode* reverseKGroup02(ListNode* head, int k) {
        if (head == nullptr) {
            return head;
        }
        ListNode *a, *b;
        a = b = head;
        // 寻找满足k的区间，不满足的话直接返回
        for (int i = 0; i < k; i++) {
            if (b == nullptr) {
                return head;
            }
            b = b->next;
        }
        // 翻转区间
        ListNode* newHead = reverse(a, b);
        // 递归翻转之后的链表，并和之前的拼接起来
        a->next = reverseKGroup02(b, k);
        return newHead;
    }

   private:
    /**
     * 翻转区间[a,b), 左闭右开区间 和迭代法翻转链表类似
     */
    ListNode* reverse(ListNode* a, ListNode* b) {
        ListNode* pre = nullptr;
        ListNode* cur = a;
        while (cur != b) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};