#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    /**
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head) return head;
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto a = dummy, b = head;
        for (int i = 0; i < m - 1; i++) a = a->next; // 前一个结点，便于将翻转的区间连接起来
        for (int i = 0; i < n; i++) b = b->next; // 正常遍历即可
        auto cur = a->next, pre = b; // 注意cur需要向后走一步，pre是之后的结点
        while (cur != b) { //翻转区间
            auto nx = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nx;
        }
        a->next = pre; // 将前面和后面部分连接起来
        return dummy->next;
    }

    /**
     * 递归
     * 将链表向后移动，直到m当作链表头结点，然后翻转链表前n-m个结点
     */
    ListNode* pos;  // 记录翻转区间的后一个结点
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