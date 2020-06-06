#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        auto dummy = new ListNode(-1);  // 构建虚拟结点
        dummy->next = head;
        ListNode *a, *b;
        a = b = dummy;
        for (int i = 0; i < m - 1; i++)
            a = a->next;  // a记录翻转起点的前一个结点
        for (int i = 0; i < n; i++) b = b->next;
        // c和d是翻转区间 实际翻转了 c-b，翻转区间内不包含d，d是终止判断条件
        auto c = a->next, d = b->next;
        auto rv = reverse(c, d);
        a->next = rv;  // 翻转区间的前一个结点指向翻转的结果
        // 此时，c成了翻转区间中的最后一个结点，最后一个结点指向翻转区间的下一个结点d
        c->next = d;
        return dummy->next;
    }

    ListNode* reverse(ListNode* a, ListNode* b) {
        ListNode* pre = nullptr;
        auto cur = a;
        while (cur != b) {
            auto nx = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nx;
        }
        return pre;
    }

    ListNode* pos;  // 记录翻转区间的后一个结点
    /**
     * 递归
     * 将链表向后移动，直到m当作链表头结点，然后翻转链表前n-m个结点
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == 1) return reverseN(head, n);
        head->next = reverseBetween(head, m - 1, n - 1);
        return head;
    }
    ListNode* reverseN(ListNode* head, int n) {
        if (n == 1) {
            pos = head->next;
            return head;
        }
        auto last = reverseN(head->next, n - 1);
        head->next->next = head;
        head->next = pos;
        return last;
    }
};