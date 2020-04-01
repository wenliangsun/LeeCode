//
// Created by wenliangsun on 2020/2/8.
//

#ifndef C__ALGORITHM_NEWCODER14_H
#define C__ALGORITHM_NEWCODER14_H

#include "ListNode.h"
#include <stack>

#endif //C__ALGORITHM_NEWCODER14_H
using std::stack;
/**
 * 题目14：链表中倒数第K个结点
 * 输入一个链表，输出该链表中的倒数第k个结点。
 */
class NewCoder14 {
public:
    /**
     * 利用栈的数据结构。
     * @param pListHead
     * @param k
     * @return
     */
    ListNode *FindKthToTail01(ListNode *pListHead, unsigned int k) {
        if (pListHead == NULL || k == 0)
            return NULL;
        stack<ListNode *> stk;
        while (pListHead != NULL) {
            stk.push(pListHead);
            pListHead = pListHead->next;
        }
        ListNode *res;
        for (int i = 0; i < k; ++i) {
            if (!stk.empty()) {
                res = stk.top();
                stk.pop();
            } else {
                return NULL;
            }
        }
        return res;
    }

    /**
     * 使用两个指针，第一个指针先走k-1步，然后和第二个指针一同向前，
     * 直到第一个指针到达链表尾端，则第一个指针所指位置即为结果。
     *
     * 相关题目：
     * （1）求链表的中间结点，如果链表中结点总数是奇数，返回中间结点，
     * 如果结点总数是偶数，返回中间两个结点的任意一个。思路：定义两个指针，一个指针一次走一步，
     * 一个指针依次走两步，当走的快的指针走到链表尾端时，走的慢的指针正好在链表的中间。
     * （2）判断一个单向链表是否形成环形结构。思路：定义两个指针，同时从链表的头结点出发，
     * 一个指针一次走一步，另一个指针一次走两步，如果快的指针追上慢的指针，那么链表就是环形链表，
     * 如果走的快的指针走到了链表的末尾（m_pnext指向NULL）都没有追上第一个指针，那么链表就不是环形链表。
     *
     * 启发：当我们用一个指针遍历链表不能解决问题时，我们可以尝试两个指针来遍历链表。
     *       可以让其中一个指针遍历的速度快一些，或者让它在链表上走若干步。
     * @param pListHead
     * @param k
     * @return
     */
    ListNode *FindKthToTail02(ListNode *pListHead, unsigned int k){
        if (pListHead==NULL || k==0)
            return NULL;
        ListNode* p = pListHead;
        for (int i = 0; i < k - 1; ++i) {
            if(p->next!=NULL){
                p = p->next;
            } else{
                return NULL;
            }
        }
        while (p->next!=NULL){
            pListHead = p->next;
            p = p->next;
        }
        return pListHead;
    }
};