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
    ListNode* deleteDuplicates(ListNode* head) {
        auto cur = head;
        while (cur) {
            if (cur->next && cur->val == cur->next->val)
                cur->next = cur->next->next;
            else
                cur = cur->next;
        }
        return head;
    }
};