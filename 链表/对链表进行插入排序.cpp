#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        auto dummy = new ListNode(-1);  // 构建虚拟结点，头结点可能会变
        dummy->next = head;
        auto pre = head;
        auto cur = head->next;
        while (cur) {
            // 如果当前待排序的结点的值小于排序部分的最后一个结点的值则需要从前向后找待排序结点的位置
            if (cur->val < pre->val) {
                auto t = dummy;
                // 从头开始遍历，寻找可以插入的位置
                while (t->next->val < cur->val) t = t->next;
                // 插入结点
                pre->next = cur->next;
                cur->next = t->next;
                t->next = cur;
                cur = pre->next;
            } else {  // 否则，直接排序下一个结点
                pre = pre->next;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};