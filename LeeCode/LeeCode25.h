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
     * 其他方法！！！
     */
    ListNode* reverseKGroup02(ListNode* head, int k) {}
};