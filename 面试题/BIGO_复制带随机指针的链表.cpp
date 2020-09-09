#include <bits/stdc++.h>

using namespace std;

/**
 * 复制带有随机指针的链表
 */

struct Node {
    int val;
    Node* next;
    Node* random;
    Node(int x) : val(x), next(nullptr), random(nullptr) {}
};

Node* copyNode(Node* head) {
    // 复制结点
    for (auto p = head; p;) {
        auto np = new Node(p->val);
        auto nx = p->next;
        p->next = np;
        np->next = nx;
        p = nx;
    }
    // 调整random指针
    for (auto p = head; p; p = p->next->next) {
        if (p->random) p->next->random = p->random->next;
    }
    // 拆分成两个链表
    auto dummy = new Node(-1);
    auto cur = dummy;
    for (auto p = head; p;) {
        auto pre = p;
        cur->next = p->next;
        cur = cur->next;
        p = p->next->next;
        pre->next = p;
    }
    return dummy->next;
}