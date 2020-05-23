//
// Created by wenliangsun on 2020/2/5.
//

#include <c++/cstddef>

#ifndef C__ALGORITHM_TREENODE_H
#define C__ALGORITHM_TREENODE_H

#endif //C__ALGORITHM_TREENODE_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {};
};