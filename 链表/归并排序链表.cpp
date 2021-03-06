#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
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

    /**
     * 递归版本
     * 时间复杂度：O(nlogn)
     * 空间复杂度：O(logn)
     */
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;  // 边界条件
        auto s = head;
        auto f = head;
        // 快慢指针找中间结点
        while (!f || !f->next) {
            f = f->next->next;
            s = s->next;
        }
        auto t = s->next;  // 断开链表
        s->next = nullptr;
        auto l = sortList(head);        // 递归排序前部分
        auto r = sortList(t);           // 递归排序后部分
        auto dummy = new ListNode(-1);  // 构建虚拟结点
        auto cur = dummy;
        // 归并两部分
        while (l && r) {
            if (l->val < r->val) {
                cur->next = l;
                l = l->next;
                cur = cur->next;
            } else {
                cur->next = r;
                r = r->next;
                cur = cur->next;
            }
        }
        while (l) {
            cur->next = l;
            l = l->next;
            cur = cur->next;
        }
        while (r) {
            cur->next = r;
            r = r->next;
            cur = cur->next;
        }
        return dummy->next;
    }
};