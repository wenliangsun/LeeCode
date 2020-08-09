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
     * 使用辅助数组
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     */
    void reorderList(ListNode* head) {
        vector<ListNode*> tmp;
        for (auto p = head; p; p = p->next) tmp.push_back(p);
        int l = 0, r = tmp.size() - 1;
        while (l < r) {
            tmp[l]->next = tmp[r];
            l++;
            if (l == r) break;
            tmp[r]->next = tmp[l];
            r--;
        }
        tmp[l]->next = nullptr;  // 注意这儿需要置空
    }

    /**
     * 找中点 翻转后面部分，再合并
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     */
    void reorderList(ListNode* head) {
        if (!head) return;
        ListNode *f, *s;
        f = s = head;
        // 寻找中点
        while (f && f->next) {
            f = f->next->next;
            s = s->next;
        }
        // 记录后半部分链表
        auto post = s->next;
        s->next = nullptr;  // 将前后部分链表断开
        // 翻转链表
        ListNode* pre = nullptr;
        while (post) {
            auto nx = post->next;
            post->next = pre;
            pre = post;
            post = nx;
        }
        //  合并链表
        while (pre) {
            auto th = head->next;
            auto tp = pre->next;
            head->next = pre;
            pre->next = th;
            head = th;
            pre = tp;
        }
    }
};