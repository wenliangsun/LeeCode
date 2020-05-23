#include <deque>
#include "ListNode.h"

using namespace std;

/**
 * 题目61：旋转链表
 */
class LeeCode61 {
   public:
    /**
     * 思路：借助双向列表数据结构，模拟循环。
     * 可优化，构建循环链表!!!
     * 时间复杂度：O(N)
     * 空间复杂度：O(N)
     */
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) {
            return nullptr;
        }
        deque<ListNode*> dq;
        int len = 0;
        // 将所有节点入队并统计链表长度
        while (head != nullptr) {
            dq.push_back(head);
            head = head->next;
            len++;
        }
        // 实现旋转
        for (int i = 0; i < k % len; i++) {
            dq.push_front(dq.back());
            dq.pop_back();
        }
        ListNode* newHead = new ListNode(0);
        ListNode* node = newHead;
        // 将旋转后的结点连接起来
        while (!dq.empty()) {
            dq.front()->next = nullptr;
            node->next = dq.front();
            node = node->next;
            dq.pop_front();
        }
        return newHead->next;
    }

    /**
     * 思路：构建循环队列，翻转后寻找断开点
     */
    ListNode* rotateRight2(ListNode* head, int k) {
        if (head == nullptr) {
            return nullptr;
        }
        int len = 0;
        ListNode* pNode = head;
        ListNode* pNewNode = head;
        // 统计链表结点数
        while (pNode->next != nullptr) {
            pNode = pNode->next;
            len++;
        }
        len++;
        // 尾结点指向头结点，构建循环队列
        pNode->next = head;
        // 寻找断开点，注意这儿的转换，需要在结点的前一个结点断开
        for (int i = 0; i < len - k % len - 1; i++) {
            pNewNode = pNewNode->next;
        }
        ListNode* newHead = pNewNode->next;
        // 将尾结点置空
        pNewNode->next = nullptr;
        return newHead;
    }
};