#include <bits/stdc++.h>

#include "ListNode.h"

using namespace std;

/**
 * 题目143：重排链表
 */

class Solution {
   public:
    /**
     * 利用数组
     * 时间复杂度：O(n)
     * 空间复杂度：O(n)
     */
    void reorderList(ListNode* head) {
        if (head == nullptr) return;
        vector<ListNode*> tmp;
        ListNode* p = head;
        while (p) {
            tmp.push_back(p);
            p = p->next;
        }
        int l = 0, r = tmp.size() - 1;
        // 双指针
        while (l < r) {
            tmp[l]->next = tmp[r];
            l++;
            if (l == r) break;
            tmp[r]->next = tmp[l];
            r--;
        }
        tmp[l]->next = nullptr;
    }

    /**
     * 找中点，对后半部分翻转，然后插入到前半部分中
     */
    void reorderList(ListNode* head) {
        if (head == nullptr) return;
        ListNode* fast = head;
        ListNode* slow = head;
        // 找中点
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* low = slow->next;
        slow->next = nullptr;
        // 翻转后面部分
        ListNode* pre = nullptr;
        while (low) {
            auto next = low->next;
            low->next = pre;
            pre = low;
            low = next;
        }
        while (pre) {
            auto th = head->next;
            auto tp = pre->next;
            head->next = pre;
            pre->next = th;
            head = th;
            pre = tp;
        }
    }
};