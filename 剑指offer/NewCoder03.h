//
// Created by wenliangsun on 2020/2/5.
//

#ifndef C__ALGORITHM_NEWCODER03_H
#define C__ALGORITHM_NEWCODER03_H

#include <iostream>
#include <vector>
#include <stack>
#include "ListNode.h"

#endif //C__ALGORITHM_NEWCODER03_H
using std::vector;
using std::stack;

/**
 * 题目3：从尾到头打印链表
 * 输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
 */
class NewCoder03 {
public:
    /**
     * 思路1：利用栈的数据结构
     * 1）首先遍历链表，并依次入栈；
     * 2）依次从栈顶弹出元素，并存入vector容器中。
     * @param head
     * @return
     */
    vector<int> printListFromTailToHead01(ListNode *head) {
        stack<int> stk;
        vector<int> res;
        if (head == NULL)
            return res;
        while (head != NULL) {
            stk.push(head->val);
            head = head->next;
        }
        while (!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }

    /**
     * 思路2：采用递归的思路，递归到链表的最后，然后向前依次添加到容器。
     * 考虑：递归停止条件
     */
    vector<int> res;
    vector<int> printListFromTailToHead02(ListNode *head) {
        if (head != NULL){ // 如果不是NULL，则将值存入res，否则向前返回。
            printListFromTailToHead02(head->next); // 进入递归
            res.push_back(head->val); // 存入容器
        }
        return res;
    }
};