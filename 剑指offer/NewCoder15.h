//
// Created by wenliangsun on 2020/2/8.
//

#ifndef C__ALGORITHM_NEWCODER15_H
#define C__ALGORITHM_NEWCODER15_H

#include "ListNode.h"
#include <stack>

#endif //C__ALGORITHM_NEWCODER15_H

using std::stack;

/**
 * 题目15：反转链表
 * 输入一个链表，反转链表后，输出新链表的表头
 * 注意：解决链表相关的问题时，总会有大量的指针操作，因此操作指针时，我们要小心谨慎。
 */
class NewCoder15 {
public:
    /**
     * 操作指针来改变链表连接方向。注意遍历的终止条件。
     * 思路：我们使用三个指针，利用两个指针来改变结点的连接方向，
     * 第三个指针用来记录之前的链表，避免链表断开。
     * @param pHead
     * @return
     */
    ListNode *ReverseList01(ListNode *pHead) {
        if (pHead == NULL)
            return NULL;
        ListNode *preNode = NULL; // 指向前一个结点的指针
        ListNode *curNode = pHead; // 指向当前结点的指针
        ListNode *reverHead = NULL; // 翻转链表的头指针
        while (curNode != NULL) { // 注意遍历链表的条件
            ListNode *posNode = curNode->next; // 指向后一个结点的指针
            if (posNode == NULL) { // 给头指针赋值的条件
                reverHead = curNode;
            }
            curNode->next = preNode; // 改变结点连接方向
            preNode = curNode;
            curNode = posNode;
        }
        return reverHead;
    }

    /**
     * 递归版本
     * 扩展：使用递归的方法实现反转链表。
     * @param pHead
     * @return
     */
    ListNode *ReverseList02(ListNode *pHead) {
        if (pHead == NULL || pHead->next == NULL) //递归终止条件
            return pHead;
        ListNode *reverHead = ReverseList02(pHead->next); // 先递归到链表尾端
        pHead->next->next = pHead; // 修改尾端结点的指向
        pHead->next = NULL; // 翻转链表的尾结点置为NULL
        return reverHead;
    }

    /**
     * 借助栈数据结构
     * 思路：先入栈，再出栈
     * @param PHead
     * @return
     */
    ListNode *ReverseList03(ListNode *pHead) {
        if(pHead==NULL || pHead->next==NULL)
            return pHead;
        stack<ListNode*> stk;
        while (pHead!=NULL){
            stk.push(pHead);
            pHead = pHead->next;
        }
        ListNode* reverHead = stk.top();
        ListNode* temp = reverHead;
        stk.pop();
        while (!stk.empty()){
            temp->next = stk.top();
            stk.pop();
        }
        return reverHead;
    }
};