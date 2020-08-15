#include <bits/stdc++.h>

using namespace std;

/**
 * 一个链表，奇数位升序偶数位降序，让链表变成升序的。比如：1 8 3 6 5 4 7 2 9，最后输出1 2 3 4 5 6 7 8 9。
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
   public:
    /**
     * 思路：先奇偶拆分出来，然后翻转降序的链表，最后合并两个排序链表
     * 时间复杂度：O(n)
     */
    ListNode* sortList(ListNode* head) {
        auto dummy1 = new ListNode(-1);
        auto dummy2 = new ListNode(-1);
        auto cur = head;
        auto p1 = dummy1, p2 = dummy2;
        int cnt = 1;
        while (cur) {
            if (cnt & 1) {
                p1->next = cur;
                p1 = p1->next;
                cur = cur->next;
            } else {
                p2->next = cur;
                p2 = p2->next;
                cur = cur->next;
            }
            cnt++;
        }
        p1->next = nullptr;
        p2->next = nullptr;
        p1 = dummy1->next;
        p2 = dummy2->next;
        ListNode* pre = nullptr;
        cur = p2;
        while (cur) {
            auto nx = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nx;
        }
        auto dummy = new ListNode(-1);
        auto p = dummy;
        while (pre && p1) {
            if (pre->val < p1->val){
                p->next = pre;
                pre = pre->next;
                p = p->next;
            } else {
                p->next = p1;
                p1 = p1->next;
                p = p->next;
            }
        }
        while (pre) {
            p->next = pre;
            pre = pre->next;
            p = p->next;
        }
        while (p1) {
            p->next = p1;
            p1 = p1->next;
            p = p->next;
        }
        return dummy->next;
    }
};

int main() {
    auto n1 = new ListNode(1);
    auto n2 = new ListNode(8);
    auto n3 = new ListNode(3);
    auto n4 = new ListNode(6);
    auto n5 = new ListNode(5);
    auto n6 = new ListNode(4);
    auto n7 = new ListNode(7);
    auto n8 = new ListNode(2);
    auto n9 = new ListNode(9);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;
    n8->next = n9;
    
    Solution s = Solution();
    auto res = s.sortList(n1);
    while (res) {
        cout << res->val << ' ';
        res = res->next;
    }
}