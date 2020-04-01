#include "TreeNode.h"

/**
 * 题目104：二叉树的最大深度
 */
class LeeCode104 {
   public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return left > right ? left + 1 : right + 1;
    }
};