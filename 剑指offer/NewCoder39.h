//
// Created by wenliangsun on 2020/2/14.
//

#ifndef C__ALGORITHM_NEWCODER39_H
#define C__ALGORITHM_NEWCODER39_H

#include "TreeNode.h"

#endif //C__ALGORITHM_NEWCODER39_H

/**
 * 题目39：平衡二叉树
 * 输入一棵二叉树，判断该二叉树是否是平衡二叉树。
 */
class NewCoder39 {
public:
    /**
     * 思路:利用求二叉树的深度的思路。
     * 先求当前节点的左子树的深度，然后求其右子树的深度，判断左右子树的深度差是否是1，
     * 然后分别判断当前结点的左子树和右子树是否是平衡二叉树。
     *
     * 注意：这种思路会导致有些结点被多次遍历，效率不高！！！
     *
     * @param pRoot
     * @return
     */
    bool IsBalanced_Solution01(TreeNode *pRoot) {
        if (pRoot == nullptr)
            return true;
        int left = TreeDepth(pRoot->left); // 求左子树的深度
        int right = TreeDepth(pRoot->right); // 求右子树的深度
        int diff = left - right;
        if (diff > 1 || diff < -1) // 判断是否是平衡数
            return false;
        return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }

    int TreeDepth(TreeNode *pRoot) {
        if (pRoot == nullptr)
            return 0;
        int left = TreeDepth(pRoot->left);
        int right = TreeDepth(pRoot->right);
        return left > right ? left + 1 : right + 1;
    }

    bool IsBalanced_Solution02(TreeNode *pRoot) {
        if (pRoot == nullptr)
            return true;
        int depth = 0;
        return IsBalanced(pRoot, &depth);

    }

    /**
     * 思路：采用后续遍历二叉树的思路！！！这样所有的结点只需要遍历一次，提高了效率！！！
     * 当遍历当前结点时，其左右子树已经遍历过了，
     * 我们只需要记录左右子树的深度即可判断当前结点下面的子树是不是平衡二叉树。
     * @param pRoot
     * @param depth 用于记录树的深度
     * @return
     */
    bool IsBalanced(TreeNode *pRoot, int *depth) {
        if (pRoot == nullptr) {
            *depth = 0;
            return true;
        }
        int left, right;
        if (IsBalanced(pRoot->left, &left) && IsBalanced(pRoot->right, &right)) { // 先遍历当前结点的左子树，然后遍历当前结点的右子树
            int diff = left - right; // 计算当前结点的左子树和右子树的深度差
            if (diff > 1 || diff < -1) { // 判断是该子树否是是平衡树
                return false; // 不是，返回false
            } else {
                *depth = left > right ? left + 1 : right + 1; // 是，深度为当前左子树和右子树的深度中较大的+1
                return true;
            }
        }
        return false;
    }
};