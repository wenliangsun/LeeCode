#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
   public:
    vector<int> res;
    /**
     * 链表的后序遍历
     */
    vector<int> reversePrint(ListNode* head) {
        dfs(head);
        return res;
    }

    void dfs(ListNode* head) {
        if (head == nullptr) return;
        dfs(head->next);
        res.push_back(head->val);
    }
};