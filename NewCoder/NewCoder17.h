//
// Created by wenliangsun on 2020/2/9.
//

#ifndef C__ALGORITHM_NEWCODER17_H
#define C__ALGORITHM_NEWCODER17_H

#include "TreeNode.h"

#endif //C__ALGORITHM_NEWCODER17_H

/**
 * 题目17：树的子结构
 * 输如两颗二叉树A,B，判断B是不是A的子结构。(ps:我们约定空树不是任意一个树的子节点)
 */
class NewCoder17 {
public:
    /**
     * 思路：实际上还是树的遍历。可递归，可非递归，递归的代码整齐
     * 1）首先遍历A树寻找与B树根节点相同的结点，如果找到，就接着判断B是不是A的子树。
     * 2）依次遍历A的左子树和右子树，寻找与B树根节点相同的结点。
     * @param pRoot1
     * @param pRoot2
     * @return
     */
    bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2) {
        bool result = false;
        if (pRoot1 != NULL && pRoot2 != NULL) { // 递归终止条件!!!
            if (pRoot1->val == pRoot2->val) {
                // 判断下面的是否子结构
                result = doseTree1HasTree2(pRoot1, pRoot2);
            }
            if (!result) { // 匹配A树中的下一个结点(左子树)
                result = HasSubtree(pRoot1->left, pRoot2);
            }
            if (!result) { // 匹配A树种的下一个结点(右子树)
                result = HasSubtree(pRoot1->right, pRoot2);
            }
        }
        return result;
    }

    /**
     * 如果匹配到了。然后判断之后的子树是否是A的子结构
     * @param tree1
     * @param tree2
     * @return
     */
    bool doseTree1HasTree2(TreeNode *tree1, TreeNode *tree2) { // 考虑if的返回的优先级！！！
        if (tree2 == NULL) // 注意，这儿先判断tree2，如果tree2是NULL的话，直接返回true
            return true;
        if (tree1 == NULL)
            return false;
        if (tree1->val != tree2->val) {
            return false;
        } else {
            return doseTree1HasTree2(tree1->left, tree2->left) && doseTree1HasTree2(tree1->right, tree2->right);
        }
    }
};