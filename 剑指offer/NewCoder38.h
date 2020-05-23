//
// Created by wenliangsun on 2020/2/14.
//

#ifndef C__ALGORITHM_NEWCODER38_H
#define C__ALGORITHM_NEWCODER38_H

#include "TreeNode.h"

#endif //C__ALGORITHM_NEWCODER38_H

/**
 * 题目38：二叉树的深度
 * 输入一棵二叉树，求该树的深度。
 * 从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
 */
class NewCoder38 {
public:
    /**
     * 思路：如果一棵树只有一个结点那么它的深度就是1，
     * 如果只有左子树，则其深度是左子树的深度+1，
     * 如果只有右子树，则其深度是右子树的深度+1
     * 如果既有左子树又有右子树，则其深度是左子树的深度和右子树的深度中较大的那个+1
     * 采用递归的思想！！！
     * @param pRoot
     * @return
     */
    int TreeDepth(TreeNode *pRoot) {
        if (pRoot == nullptr)
            return 0;
        int left = TreeDepth(pRoot->left);
        int right = TreeDepth(pRoot->right);
        return left > right ? left + 1 : right + 1;
    }
};