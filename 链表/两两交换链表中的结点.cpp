#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        auto t = head->next;
        head->next = swapPairs(t->next);
        t->next = head;
        return t;
    }
};