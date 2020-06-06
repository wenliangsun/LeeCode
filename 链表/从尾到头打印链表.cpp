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
    vector<int> reversePrint(ListNode* head) {
        dfs(head);
        return res;
    }

    void dfs(ListNode* head) {
        if (!head) return;
        dfs(head->next);
        res.push_back(head->val);
    }
};