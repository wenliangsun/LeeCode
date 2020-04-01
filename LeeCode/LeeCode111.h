#include "TreeNode.h"

/**
 * 题目111：二叉树的最小深度
 */
class LeeCode111 {
   public:
    /**
     * 思路：递归法
     * 注意审题 最小深度的定义是啥！！！
     * 递归结束条件：
     * 叶子结点的定义是左孩子和右孩子都为null时才叫叶子结点
     * 当root结点左孩子和右孩子都为null时，返回1
     * 当root结点中有一个孩子是null时，返回另一个非null孩子的深度
     * 当root的两个孩子都不为null时，返回两个孩子中较小的深度
     */
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        //左孩子为null(left为0)，右孩子为null(right为0)
        //，左右孩子都为null(left,right都为0)
        if (root->left == nullptr || root->right == nullptr) {
            return left + right + 1;
        }
        // 左右孩子都不为null时
        return min(left, right) + 1;
    }

    /**
     * 迭代版 DFS
     */
    int minDepth2(TreeNode* root) {}
    /**
     * 迭代版 BFS
     */
    int minDepth3(TreeNode* root) {}
};