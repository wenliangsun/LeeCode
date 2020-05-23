#include <bits/stdc++.h>

#include "ListNode.h"

using namespace std;

/**
 * 题目147：对链表进行插入排序
 */

class Solution {
   public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* dummy = new ListNode(-1);  //构建虚拟结点  因为头结点可能会变
        dummy->next = head;
        ListNode* pre = head;        // 指向排序部分的最后一个结点
        ListNode* cur = head->next;  // 指向当前需要排序的结点

        while (cur) {
            // 如果当前待排序的结点的值小于排序部分的最后一个结点的值则需要从前向后找待排序结点的位置
            if (cur->val < pre->val) {
                auto t = dummy;
                // 从头开始遍历
                while (t->next->val < cur->val) {
                    t = t->next;
                }
                // 插入结点
                pre->next = cur->next;
                cur->next = t->next;
                t->next = cur;
                cur = pre->next;
                // 否则说明不用交换已经排好序了，排序下一个结点
            } else {
                pre = pre->next;
                cur = cur->next;
            }
        }

        return dummy->next;
    }
};