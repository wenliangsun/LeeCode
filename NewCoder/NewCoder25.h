//
// Created by wenliangsun on 2020/2/11.
//

#ifndef C__ALGORITHM_NEWCODER25_H
#define C__ALGORITHM_NEWCODER25_H

#include "RandomListNode.h"

#endif //C__ALGORITHM_NEWCODER25_H

/**
 * 题目25：复杂链表的复制
 * 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，
 * 另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
 * （注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
 */
class NewCoder25 {
public:
    /**
     * 思路：分治法
     * 1）先拷贝结点，A-B-C --> A-A'-B-B'-C-C'；
     * 2）修改拷贝后A',B',C'的random指针；
     * 3）将链表拆分。
     * @param pHead
     * @return
     */
    RandomListNode *Clone(RandomListNode *pHead) {
        if (pHead == NULL)
            return NULL;
        cloneNode(pHead);
        cloneRandom(pHead);
        return reconnect(pHead);
    }

    void cloneNode(RandomListNode *pHead) {
        RandomListNode *pNode = pHead;
        while (pNode != NULL) {
            RandomListNode *clone = new RandomListNode(pNode->label);
            clone->next = pNode->next;
            pNode->next = clone;
            pNode = clone->next;
        }
    }

    void cloneRandom(RandomListNode *pHead) {
        RandomListNode *pNode = pHead;
        while (pNode != NULL) {
            RandomListNode *clone = pNode->next;
            if (pNode->random != NULL) // 考虑Random没有指向的情况！！！
                clone->random = pNode->random->next;
            pNode = clone->next;
        }
    }

    RandomListNode *reconnect(RandomListNode *pHead) {
        RandomListNode *pCloneHead = pHead->next;
        RandomListNode *pNode = pHead;
        while (pNode != NULL) {
            RandomListNode *clone = pNode->next;
            pNode->next = clone->next;
            pNode = clone->next;
            if (pNode != NULL) // 注意！！
                clone->next = pNode->next;
        }
        return pCloneHead;
    }

    RandomListNode *Clone2(RandomListNode *pHead) {
        if (pHead == NULL)
            return NULL;
        RandomListNode *pCloneHead = new RandomListNode(pHead->label);
        RandomListNode *pNode = pCloneHead;
        while (pHead->next != NULL) {
            RandomListNode *clone = new RandomListNode(pHead->next->label);
            if (pHead->random != NULL) {
                pNode->random = new RandomListNode(pHead->random->label);
            }
            pNode->next = clone;
            pNode = pNode->next;
            pHead = pHead->next;
        }
        return pCloneHead;
    }
};