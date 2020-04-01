#include "TreeNode.h"

/**
 * 题目110：平衡二叉树
 */
class LeeCode110 {
   public:
    /**
     * 思路：递归法  自顶至下
     * 首先计算左右子树的高度，然后判断是否满足平衡二叉树
     * 时间复杂度：O(NlogN) 可优化
     * 空间复杂度：O(N)
     */
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        int left = helper(root->left);    //左子树高度
        int right = helper(root->right);  // 右子树高度
        int diff = abs(left - right);
        return diff < 2 && isBalanced(root->left) && isBalanced(root->right);
    }

   private:
    /**
     * 二叉树的最大深度
     */
    int helper(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = helper(root->left);
        int right = helper(root->right);
        return left > right ? left + 1 : right + 1;
    }

    /**
     * 思路：对二叉树进行先序遍历，从底至顶返回子树最大高度，
     * 若判断不是平衡树则一直向上返回。
     * 时间复杂度：O(N)
     * 空间复杂度：O(N)
     */
    int helper2(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = helper2(root->left);
        if (left == -1) {
            return -1;
        }
        int right = helper2(root->right);
        if (right == -1) {
            return -1;
        }
        return abs(left - right) < 2 ? max(left, right) + 1 : -1;
    }
};