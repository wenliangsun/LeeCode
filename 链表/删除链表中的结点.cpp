#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    void deleteNode(ListNode* node) {
        // 转换为删除下一个结点
        node->val = node->next->val;
        node->next = node->next->next;
    }
};