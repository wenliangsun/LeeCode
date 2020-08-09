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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto pre = dummy, cur = head;
        while (cur->next) {
            if (cur->val != cur->next->val) { // 如果当前结点和下一个结点不同时进行判断
                if (pre->next != cur) pre->next = cur->next; // 如果pre的next指针指向的不是cur，则说明有重复
                else pre = cur; // 否则没有重复
            }
            cur = cur->next;
        }
        if (pre->next != cur) pre->next = cur->next; // 特殊情况，所有元素都相同的时候
        return dummy->next;
    }
};