#include <bits/stdc++.h>

using namespace std;

class Node {
   public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
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
        // 更新复制结点的random指针
        for (auto p = head; p; p = p->next->next)
            if (p->random) p->next->random = p->random->next;
        // 拆分链表
        auto dummy = new Node(-1);
        auto cur = dummy;
        for (auto p = head; p;) {
            auto pre = p;  // 复原原来的链表
            cur->next = p->next;
            cur = cur->next;
            p = p->next->next;
            pre->next = p;
        }
        return dummy->next;
    }

    /**
     * 还可以用哈希表来存源节点和复制结点之间的关系
     * 参考128题，复制带随机指针的链表
     */
    Node* copyRandomList(Node* head) {}
};