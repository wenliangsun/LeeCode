#include <bits/stdc++.h>

using namespace std;

class Node {
   public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        // 复制结点
        for (auto p = head; p;) {
            auto np = new Node(p->val);
            auto next = p->next;
            p->next = np;
            np->next = next;
            p = next;
        }
        // 更新Random指针
        for (auto p = head; p; p = p->next->next)
            if (p->random) p->next->random = p->random->next;
        // 拆分链表
        auto dummy = new Node(-1);
        auto cur = dummy;
        for (auto p = head; p;) {
            auto pre = p;
            cur->next = p->next;
            cur = cur->next;
            p = p->next->next;
            pre->next = p;  // 还原原链表
        }
        return dummy->next;
    }
};