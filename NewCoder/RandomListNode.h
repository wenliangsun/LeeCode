//
// Created by wenliangsun on 2020/2/11.
//

#include <c++/cstddef>

#ifndef C__ALGORITHM_RANDOMLISTNODE_H
#define C__ALGORITHM_RANDOMLISTNODE_H

#endif //C__ALGORITHM_RANDOMLISTNODE_H

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;

    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {}
};