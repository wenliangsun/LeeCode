//
// Created by wenliangsun on 2020/2/11.
//

#ifndef C__ALGORITHM_NEWCODER26_H
#define C__ALGORITHM_NEWCODER26_H

#include "TreeNode.h"
#include <vector>

#endif //C__ALGORITHM_NEWCODER26_H
using std::vector;

/**
 * 二叉搜索树与双向链表
 * 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
 * 要求不能创建任何新的结点，只能调整树中结点指针的指向。
 */
class NewCoder26 {
public:
    vector<TreeNode *> arr;
    /**
     * 采用辅助vector，先中序遍历树，然后再对遍历的结果调整指针。
     * @param pRootOfTree
     * @return
     */
    TreeNode *Convert(TreeNode *pRootOfTree) {
        if (pRootOfTree == NULL)
            return NULL;
        midTree(pRootOfTree);
        for (int i = 0; i < arr.size() - 1; ++i) {
            arr[i]->right = arr[i + 1];
            arr[i + 1]->left = arr[i];
        }
        return arr[0];
    }

    void midTree(TreeNode *tree) { // 中序遍历树
        if (tree == NULL)
            return;
        midTree(tree->left);
        arr.push_back(tree);
        midTree(tree->right);
    }

};