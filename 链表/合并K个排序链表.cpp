#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (!lists.size()) return nullptr;
        auto dummy = new ListNode(-1);
        auto p = dummy;
        while (true) {
            int minV = INT_MAX;
            bool flag = true;
            int idx = 0;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] && lists[i]->val < minV) {
                    minV = lists[i]->val;
                    idx = i;
                    flag = false;
                }
            }
            if (flag) break;
            p->next = lists[idx];
            lists[idx] = lists[idx]->next;
            p = p->next;
        }
        return dummy->next;
    }
};