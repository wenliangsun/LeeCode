#include <bits/stdc++.h>

using namespace std;

/**
 * 归并排序链表
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
   public:
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

    /**
     * 迭代版
     * 时间复杂度：O(nlogn)
     * 空间复杂度：O(1)
     */
    ListNode* sortList(ListNode* head) {
        int n = 0;
        for (auto p = head; p; p = p->next) n++; // 统计节点数量
        auto dummy = new ListNode(-1); // 构建虚拟结点
        dummy->next = head;
        // 枚举区间长度
        for (int i = 1; i < n; i *= 2) {
            auto cur = dummy;
            // 枚举每隔两个区间的起点
            for (int j = 0; j + i < n; j += i * 2) {
                auto first = cur->next, second = first;
                // 寻找第二个区间的起点
                for (int k = 0; k < i; k++) second = second->next;
                int f = 0, s = 0;
                // 归并
                while (f < i && s < i && second) {
                    if (first->val < second->val) {
                        cur->next = first;
                        cur = cur->next;
                        first = first->next;
                        f++;
                    } else{
                        cur->next = second;
                        cur = cur->next;
                        second = second->next;
                        s++;
                    }
                }
                while (f < i) {
                    cur->next = first;
                    cur = cur->next;
                    first = first->next;
                    f++;
                }
                while (s < i && second) {
                    cur->next = second;
                    cur = cur->next;
                    second = second->next;
                    s++;
                }
                // 转到下下一个区间
                cur->next = second;
            }
        }
        return dummy->next;
    }
};