#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
   public:
    /**
     *  前后指针，注意需要构建一个虚拟结点，因为头结点有可能被删除，其余操作就是链表的常规操作
     */
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = head;
        while (cur) {
            if (cur->val == val) {
                pre->next = cur->next;
                cur = cur->next;
            }
            cur = cur->next;
            pre = pre->next;
        }
        return dummy->next;
    }
};