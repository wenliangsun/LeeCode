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
        stack<int> s1, s2;  // 使用栈数据结构
        for (auto p = l1; p; p = p->next) s1.push(p->val);
        for (auto p = l2; p; p = p->next) s2.push(p->val);
        int carry = 0;
        ListNode* res = nullptr;
        while (s1.size() || s2.size() || carry) {
            int n1 = s1.size() ? s1.top() : 0;
            if (s1.size()) s1.pop();
            int n2 = s2.size() ? s2.top() : 0;
            if (s2.size()) s2.pop();
            int sum = (n1 + n2 + carry) % 10;
            auto node = new ListNode(sum);
            node->next = res;
            res = node;
            carry = (n1 + n2 + carry) / 10;
        }
        return res;
    }
};