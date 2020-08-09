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
     * 递归
     * 时间复杂度：O(n)
     * 空间复杂度：O(n)
     */
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        auto t = head->next;
        head->next = swapPairs(t->next);
        t->next = head;
        return t;
    }

    /**
     * 迭代
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     */
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto p = dummy;
        auto cur = head;
        while (cur && cur->next) {
            auto nx = cur->next;
            cur->next = nx->next;
            nx->next = cur;
            p->next = nx;
            p = cur;
            cur = cur->next;
        }
        return dummy->next;
    }
};