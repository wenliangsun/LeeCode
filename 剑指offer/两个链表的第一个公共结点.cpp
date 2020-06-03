#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
   public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto p = headA, q = headB;
        while (p != q) {
            if (p)
                p = p->next;
            else
                p = headB;
            if (q)
                q = q->next;
            else
                q = headA;
        }
        return p;
    }
};