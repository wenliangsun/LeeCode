#include <bits/stdc++.h>

using namespace std;

/**
 * 题目234：回文链表
 */

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
    ListNode* left;

   public:
    /**
     * 快慢指 + 翻转链表
     * 时间复杂度：O(N)
     * 空间复杂度：O(1)
     */
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast) slow = slow->next;
        ListNode* left = head;
        ListNode* right = reverse(slow);
        while (right) {
            if (left->val != right->val) return false;
            left = left->next, right = right->next;
        }
        return true;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur) {
            auto t = cur->next;
            cur->next = pre;
            pre = cur;
            cur = t;
        }
        return pre;
    }

    /**
     * 思路：链表的后序遍历
     *
     * 时间复杂度：O(N)
     * 空间复杂度：O(N)
     */
    bool isPalindrome(ListNode* head) {
        left = head;
        return helper(head);
    }

    bool helper(ListNode* head) {
        if (head == nullptr) return true;
        bool res = helper(head->next);
        res = res && (left->val == head->val);
        left = left->next;
        return res;
    }
};