#include <bits/stdc++.h>

using namespace std;

/**
 * 快排排序链表
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
   public:
    ListNode* quickSortList(ListNode* head) {
        //链表快速排序
        if (!head || !head->next) return head;
        qsortList(head, nullptr);
        return head;
    }
    void qsortList(ListNode* head, ListNode* tail) {
        //链表范围是[low, high)
        if (head != tail && head->next != tail) {
            ListNode* mid = partitionList(head, tail);
            qsortList(head, mid);
            qsortList(mid->next, tail);
        }
    }
    ListNode* partitionList(ListNode* low, ListNode* high) {
        //链表范围是[low, high)
        int key = low->val;
        ListNode* loc = low;
        for (ListNode* i = low->next; i != high; i = i->next)
            if (i->val < key) {
                loc = loc->next;
                swap(i->val, loc->val);
            }
        swap(loc->val, low->val);
        return loc;
    }
};