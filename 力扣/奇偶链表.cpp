#include <bits/stdc++.h>

using namespace std;

/**
 * 题目328：奇偶链表
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
   public:
    /**
     * 链表的指针操作 注意细节！！！
     */
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        ListNode* t_head = p2;
        ListNode* p = p2->next;
        if (p2) p2->next = nullptr;
        int cnt = 1;
        while (p) {
            auto t = p->next;
            // 奇数项
            if (cnt % 2) {
                p1->next = p;
                p1 = p1->next;
                if (p1) p1->next = nullptr;
                // 偶数项
            } else {
                p2->next = p;
                p2 = p2->next;
                if (p2) p2->next = nullptr;
            }
            p = t;
            cnt++;
        }
        // 拼接起来
        p1->next = t_head;
        return head;
    }
};