#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* removeElements(ListNode* head, int val) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto cur = head, pre = dummy;
        while (cur) {
            if (cur->val == val) {
                pre->next = cur->next;
                cur = cur->next;
            } else {
                pre = pre->next;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
