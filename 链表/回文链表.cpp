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
     * 找中点，翻转后半段，然后比较
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     */
    bool isPalindrome(ListNode* head) {
        auto f = head, s = head;
        while (f && f->next) {
            f = f->next->next;
            s = s->next;
        }
        if (f) s = s->next;
        ListNode* pre = nullptr;
        while (s) {
            auto nx = s->next;
            s->next = pre;
            pre = s;
            s = nx;
        }
        f = head;
        while (pre) {
            if (pre->val != f->val) return false;
            pre = pre->next;
            f = f->next;
        }
        return true;
    }

    ListNode* left;
    /**
     * 时间复杂度：O(n)
     * 空间复杂度：O(n) 栈空间
     */
    bool isPalindrome(ListNode* head) {
        left = head;
        return helper(head);
    }

    bool helper(ListNode* head) {
        if (!head) return true;
        bool res = helper(head->next);
        res = res && (left->val == head->val);
        left = left->next;
        return res;
    }
};