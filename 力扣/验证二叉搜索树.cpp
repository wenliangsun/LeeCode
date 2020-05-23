#include "TreeNode.h"

/**
 * 题目98：验证二叉搜索树
 */
class LeeCode98 {
   public:
    /**
     * 思路：递归法
     * 利用二叉搜索树的性质
     * 注意：不能仅仅判断左右结点，而是要判断左右子树中的最小和最大结点！！！
     */
    bool isValidBST(TreeNode* root) { return helper(root, nullptr, nullptr); }

    /**
     * 思路：采用中序遍历，利用二叉搜索树的性质，然后判断新添进来的数和上一个数之间的关系
     * 采用非递归版本的中序遍历
     */
    bool isValidBST2(TreeNode* root) { return helper(root, nullptr, nullptr); }

   private:
    bool helper(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if (root == nullptr) {
            return true;
        }
        if (minNode != nullptr && root->val <= minNode->val) {
            return false;
        }
        if (maxNode != nullptr && root->val >= maxNode->val) {
            return false;
        }
        return helper(root->left, minNode, root) &&
               helper(root->right, root, maxNode);
    }
};