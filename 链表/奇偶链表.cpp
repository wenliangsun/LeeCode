#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        auto p1 = head, p2 = head->next;  // 分别是奇数链表和偶数链表的头结点
        auto p = p2, cur = p2->next;  // p是偶数链表的头结点，cur是当前结点
        if (p2) p2->next = nullptr;
        int cnt = 1;
        while (cur) {
            auto t = cur->next;
            // 奇数结点
            if (cnt % 2) {
                p1->next = cur;
                p1 = p1->next;
                if (p1) p1->next = nullptr;
            } else {  // 偶数结点
                p2->next = cur;
                p2 = p2->next;
                if (p2) p2->next = nullptr;
            }
            cur = t;
            cnt++;
        }
        // 拼起来
        p1->next = p;
        return head;
    }
};