//
// Created by wenliangsun on 2020/2/5.
//

#ifndef C__ALGORITHM_NEWCODER04_H
#define C__ALGORITHM_NEWCODER04_H

#include <vector>
#include "TreeNode.h"

#endif //C__ALGORITHM_NEWCODER04_H
using std::vector;
/**
 * 题目4：重建二叉树
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 * 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
 */
class NewCoder04 {
public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if (pre.size() <= 0 || vin.size() <= 0)
            return NULL;
        int *pPreStart = &pre[0];
        int *pPreEnd = &pre[pre.size() - 1];
        int *pVinStart = &vin[0];
        int *pVinEnd = &vin[vin.size() - 1];
        return constructCore(pPreStart, pPreEnd, pVinStart, pVinEnd);

    }

    TreeNode *constructCore(int *pPreStart, int *pPreEnd, int *pVinStart, int *pVinEnd) {
        TreeNode *root = new TreeNode(*pPreStart);
        if (pPreStart == pPreEnd) { // 迭代终止条件
            if (pVinStart == pVinEnd && *pPreStart == *pVinStart)
                return root;
        }

        int *p = pVinStart;
        while (p <= pVinEnd && *p != *pPreStart) // 在中序遍历中找根节点
            ++p;
        int length = p - pVinStart; // 计算找了几步
        if (length > 0) { // 构建左子树
            root->left = constructCore(pPreStart + 1, pPreStart + length, pVinStart, p - 1);
        }
        if (length < pPreEnd - pPreStart) { // 构建右子树
            root->right = constructCore(pPreStart + length + 1, pPreEnd, p + 1, pVinEnd);
        }
        return root;
    }
};