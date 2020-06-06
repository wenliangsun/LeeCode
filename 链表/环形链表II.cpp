#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *f, *s;
        f = s = head;
        while (f && f->next) {  // 寻找相遇的结点
            f = f->next->next;
            s = s->next;
            if (s == f) break;
        }
        // 判断是否有环
        if (!f || !f->next) return nullptr;
        s = head;  // 慢指针设置为头结点
        // 一同遍历，再次相遇时即为第一个公共结点
        while (s != f) {
            s = s->next;
            f = f->next;
        }
        return s;
    }
};