#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        int len = 0;
        auto p = head, q = head;
        // 统计链表的长度
        for (; p->next; p = p->next) len++;
        len++;
        k %= len;        // 取余提高效率
        p->next = head;  // 构建循环链表
        // 寻找断开的前一个结点
        for (int i = 0; i < len - k - 1; i++) q = q->next;
        auto nx = q->next;
        q->next = nullptr;
        return nx;
    }
};