#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* left;
    bool isPalindrome(ListNode* head) {
        left = head;
        return helper(head);
    }

    bool helper(ListNode* head) {
        if (!head) return true;
        bool res = helper(head->next);
        res = res && (left->val == head->val);
        left = left->next;
        return res;
    }
};