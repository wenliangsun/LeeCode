#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto pre = dummy;
        auto cur = head;
        while (cur->next) {
            if (cur->val != cur->next->val) {
                if (pre->next == cur)
                    pre = cur;
                else
                    pre->next = cur->next;
            }
            cur = cur->next;
        }
        if (pre->next != cur) pre->next = cur->next;
        return dummy->next;
    }
};