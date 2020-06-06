#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        auto cur = head;
        while (cur) {
            auto nx = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nx;
        }
        return pre;
    }
    /**
     * 递归版本
     */
    ListNode* reverseList(ListNode* head) {
        if (!head) return;
        auto last = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
};