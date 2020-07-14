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
        return merge(lists, 0, lists.size() - 1);
    }
    // 分治 时间复杂度 O(knlogk)
    ListNode* merge(vector<ListNode*>& lists, int l, int r) {
        if (l == r) return lists[l];
        if (l < r) {
            int mid = (l + r) >> 1;
            return mergeLists(merge(lists, l, mid), merge(lists, mid + 1, r));
        }
        return nullptr;
    }

    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
        auto dummy = new ListNode(-1);
        auto p = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
                p = p->next;
            } else {
                p->next = l2;
                l2 = l2->next;
                p = p->next;
            }
        }
        while (l1) {
            p->next = l1;
            l1 = l1->next;
            p = p->next;
        }
        while (l2) {
            p->next = l2;
            l2 = l2->next;
            p = p->next;
        }
        return dummy->next;
    }

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