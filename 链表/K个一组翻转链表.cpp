#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return head;
        ListNode *a, *b;
        a = b = head;
        // 寻找区间端点，如果不够k，则直接返回
        for (int i = 0; i < k; i++) {
            if (!b) return head;
            b = b->next;
        }
        auto newHead = reverse(a, b);
        a->next = reverseKGroup(b, k);
        return newHead;
    }

    /**
     * 翻转区间
     */
    ListNode* reverse(ListNode* a, ListNode* b) {
        ListNode* pre = nullptr;
        auto cur = a;
        while (cur != b) {
            auto nx = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nx;
        }
        return pre;
    }
};