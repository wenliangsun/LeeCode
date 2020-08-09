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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return head;
        auto a = head, b = head;
        // 寻找区间
        for (int i = 0; i < k; i++) {
            if (!b) return head; // 不够k
            b = b->next;
        }

        // 翻转区间
        ListNode* pre = nullptr;
        auto cur = a;
        while (cur != b) {
            auto nx = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nx;
        }
        a->next = reverseKGroup(b, k);
        return pre;
    }
};