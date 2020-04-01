//
// Created by wenliangsun on 2020/2/9.
//

#ifndef C__ALGORITHM_NEWCODER18_H
#define C__ALGORITHM_NEWCODER18_H

#include "TreeNode.h"

#endif //C__ALGORITHM_NEWCODER18_H

/**
 * 题目18：二叉树的镜像
 * 操作给定的二叉树，将其变换为源二叉树的镜像
 */
class NewCoder18 {
public:
    /**
     * 思路：遍历树，依次交换左右子树，利用递归！
     * 画图使得问题具体化
     * @param pRoot
     */
    void Mirror(TreeNode *pRoot) {
        if (pRoot != NULL) { //如果不是叶子结点，就交换左右子树
            TreeNode *temp = pRoot->left;
            pRoot->left = pRoot->right;
            pRoot->right = temp;
        }
        if (pRoot != NULL && pRoot->left != NULL) // 注意这儿的条件，pRoot不是NULL时，才会有left指针，否则会报错！！！
            Mirror(pRoot->left);
        if (pRoot != NULL && pRoot->right != NULL) // 与之前的条件情况类似
            Mirror(pRoot->right);
    }
};