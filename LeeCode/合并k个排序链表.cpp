#include <climits>
#include <vector>
#include "ListNode.h"

using namespace std;

/**
 * 题目23：合并K个排序链表
 */
class LeeCode23 {
   public:
    /**
     * 思路：逐一合并
     * 时间复杂度O(kN)
     */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        ListNode* newHead = new ListNode(0);
        ListNode* node = newHead;
        while (true) {
            int min = INT_MAX;  // 记录每轮的最小值
            bool flag = true;   // 所有链表都为null的标志
            int index = 0;      // 最小的链表所在位置
            for (int i = 0; i < lists.size(); i++) {
                // 更新最小值，和最小值对应的索引
                if (lists[i] != nullptr && lists[i]->val < min) {
                    min = lists[i]->val;
                    index = i;
                    flag = false;
                }
            }
            // 如果链表都是null，跳出循环
            if (flag) {
                break;
            }
            // 否则将最小的结点拼接在新链表上
            node->next = lists[index];
            lists[index] = lists[index]->next;
            node = node->next;
        }
        return newHead->next;
    }

    /**
     * 思路：其他解法
     */
    ListNode* mergeKLists(vector<ListNode*>& lists) {}
};