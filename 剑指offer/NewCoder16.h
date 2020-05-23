//
// Created by wenliangsun on 2020/2/9.
//

#ifndef C__ALGORITHM_NEWCODER16_H
#define C__ALGORITHM_NEWCODER16_H

#include "ListNode.h"

#endif //C__ALGORITHM_NEWCODER16_H

/**
 * 题目16：合并两个排序的链表
 * 输入两个单调递增的链表，输出两个链表合成后的链表，需要合成后的链表满足单调不减规则。
 */
class NewCoder16 {
public:
    /**
     * 递归实现合并链表
     * 代码再好好理解理解！！！
     * @param pHead1
     * @param pHead2
     * @return
     */
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {
        if (pHead1 == NULL)
            return pHead2;
        if (pHead2 == NULL)
            return pHead1;
        ListNode *mergeHead = NULL;
        if (pHead1->val < pHead2->val) {
            mergeHead = pHead1;
            mergeHead->next = Merge(pHead1->next, pHead2);
        } else {
            mergeHead = pHead2;
            mergeHead->next = Merge(pHead1, pHead2->next);
        }
        return mergeHead;
    }
};