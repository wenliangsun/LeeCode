//
// Created by wenliangsun on 2020/2/5.
//

#include <c++/clocale>

#ifndef C__ALGORITHM_LISTNODE_H
#define C__ALGORITHM_LISTNODE_H

#endif //C__ALGORITHM_LISTNODE_H

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
            val(x), next(NULL) {
    }
    ListNode();
};