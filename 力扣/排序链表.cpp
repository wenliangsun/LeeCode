#include <bits/stdc++.h>

using namespace std;

/**
 * 题目148：排序链表
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
   public:
    /**
     * 思路：自底向上的归并排序，使用循环
     *
     * 时间复杂度：O(nlogn)
     * 空间复杂度：O(1)
     */
    ListNode* sortList(ListNode* head) {
        int n = 0;
        for (auto p = head; p; p = p->next) n++;
        auto dummy = new ListNode(-1);
        dummy->next = head;
        // 枚举区间长度
        for (int i = 1; i < n; i *= 2) {
            auto cur = dummy;
            // 遍历所有区间
            for (int j = 0; j + i < n; j += i * 2) {
                auto first = cur->next, second = first;
                // 寻找下一个区间的起点
                for (int k = 0; k < i; k++) second = second->next;
                int f = 0, s = 0;
                // 归并两个区间
                while (f < i && s < i && second) {
                    if (first->val <= second->val) {
                        cur->next = first;
                        cur = first;
                        first = first->next;
                        f++;
                    } else {
                        cur->next = second;
                        cur = second;
                        second = second->next;
                        s++;
                    }
                }
                while (f < i) {
                    cur->next = first;
                    cur = first;
                    first = first->next;
                    f++;
                }
                while (s < i && second) {
                    cur->next = second;
                    cur = second;
                    second = second->next;
                    s++;
                }
                // 指向下一个区间
                cur->next = second;
            }
        }
        return dummy->next;
    }
};