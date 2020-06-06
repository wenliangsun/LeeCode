#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
   public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *s, *f;
        f = s = head;
        for (int i = 0; i < k; i++) f = f->next;
        while (f) {
            f = f->next;
            s = s->next;
        }
        return s;
    }
};
