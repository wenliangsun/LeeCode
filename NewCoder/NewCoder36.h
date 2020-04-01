//
// Created by wenliangsun on 2020/2/13.
//

#ifndef C__ALGORITHM_NEWCODER36_H
#define C__ALGORITHM_NEWCODER36_H

#include "ListNode.h"

#endif //C__ALGORITHM_NEWCODER36_H

/**
 * 题目36：两个链表的第一个公共子节点
 * 输出两个链表，找出他们的第一个公共结点
 */
class NewCoder36 {
public:
    /**
     * 思路1：遍历第一个链表的每一个结点，并判断该节点是否是第一个公共结点；
     * (1) 遍历第一个链表，对第一个链表的每一个结点，我们做第二步；
     * (2) 遍历第二个链表，并判断是否与第一个结点相同，若相同则返回，否则跳第一步。
     * @param pHead1
     * @param pHead2
     * @return
     */
    ListNode *FindFirstCommonNode01(ListNode *pHead1, ListNode *pHead2) {
        if (pHead1 == nullptr || pHead2 == nullptr)
            return nullptr;
        ListNode *pNode1 = pHead1;
        ListNode *pNode2 = pHead2;
        while (pNode1 != nullptr) {
            while (pNode2 != nullptr) {
                if (pNode1 == pNode2) {
                    return pNode1;
                }
                pNode2 = pNode2->next;
            }
            pNode1 = pNode1->next;
        }
        return nullptr;
    }

    /**
     * 思路：长+短 短+长 对上相当于遍历了两次，然后得到第一个公共结点
     * @param pHead1
     * @param pHead2
     * @return
     */
    ListNode *FindFirstCommonNode02(ListNode *pHead1, ListNode *pHead2) {
        ListNode *pNode1 = pHead1;
        ListNode *pNode2 = pHead2;
        while (pNode1 != pNode2) {
            pNode1 = pNode1 == nullptr ? pHead2 : pNode1->next;
            pNode2 = pNode2 == nullptr ? pHead1 : pNode2->next;
        }
        return pNode1;
    }

    /**
     * 思路：首先统计每个链表的长度，然后计算出两链表的差值；
     * 先将较长的链表先走差值步，然后和另一个链表一起遍历，直到找到第一个公共结点
     * @param pHead1
     * @param pHead2
     * @return
     */
    ListNode *FindFirstCommonNode03(ListNode *pHead1, ListNode *pHead2) {
        int lenList1 = 0;
        int lenList2 = 0;
        ListNode *pNode1 = pHead1;
        ListNode *pNode2 = pHead2;
        while (pNode1 != nullptr) {
            lenList1++;
            pNode1 = pNode1->next;
        }
        while (pNode2 != nullptr) {
            lenList2++;
            pNode2 = pNode2->next;
        }
        int diff;
        ListNode *pLongList;
        ListNode *pShortList;
        if (lenList1 > lenList2) {
            pLongList = pHead1;
            pShortList = pHead2;
            diff = lenList1 - lenList2;
        } else {
            pLongList = pHead2;
            pShortList = pHead1;
            diff = lenList2 - lenList1;
        }
        for (int i = 0; i < diff; ++i) {
            pLongList = pLongList->next;
        }
        while (pLongList != nullptr && pShortList != nullptr && pLongList != pShortList) {
            pLongList = pLongList->next;
            pShortList = pShortList->next;
        }
        return pLongList;
    }
};