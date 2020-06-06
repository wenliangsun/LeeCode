#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto dummy = new ListNode(-1);
        auto p = dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = (n1 + n2 + carry) % 10;
            carry = (n1 + n2 + carry) / 10;
            p->next = new ListNode(sum);
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            p = p->next;
        }
        return dummy->next;
    }
};