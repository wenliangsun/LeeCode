#include "TreeLinkNode.h"

/**
 * 题目57：二叉树的下一个结点
 * 给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
 * 注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
 *
 */
class NewCoder57 {
   public:
    /**
     * 思路：画图考虑每种情况！！！ 中序遍历 ：左根右
     * 1. 结点为空，返回null
     * 2. 结点的右子树存在：
     *      下一个结点是沿右子树的左子结点一直遍历，直到叶子结点即为下一个结点。
     * 3.结点的右子树不存在：
     *      向上寻找该节点位于其左子树的第一个父节点，则该父节点即为下一个结点。
     */
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if (pNode == nullptr) {
            return nullptr;
        }
        if (pNode->right != nullptr) {  // 如果结点有右子树
            pNode = pNode->right;
            // 沿左子节点遍历到叶子结点即为下一个结点
            while (pNode->left != nullptr) {
                pNode = pNode->left;
            }
            return pNode;
        } else {                              // 如果结点无右子树
            while (pNode->next != nullptr) {  // 向上寻找
                if (pNode->next->left == pNode) {  // 当前结点是其父节点的左子树
                    return pNode->next;
                }
                pNode = pNode->next;
            }
        }
        return nullptr;
    }
};