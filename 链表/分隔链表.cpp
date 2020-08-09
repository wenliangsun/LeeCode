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
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     */
    ListNode* partition(ListNode* head, int x) {
        if (!head) return nullptr;
        ListNode* l1 = new ListNode(0); // 小于x的结点
        ListNode* l2 = new ListNode(0); // 大于等于x的阶段， 
        auto p1 = l1;
        auto p2 = l2;
        while (head) {
            if (head->val < x) {
                p1->next = head;
                p1 = p1->next;
            } else {
                p2->next = head;
                p2 = p2->next;
            }
            head = head->next;
        }
        // 特判
        if (p1 == l1) return l2->next;
        if (p2 == l2) return l1->next;
        p1->next = l2->next;
        p2->next = nullptr;
        return l1->next;
    }
};