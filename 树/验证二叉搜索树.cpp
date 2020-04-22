#include <climits>

#include "TreeNode.h"

/**
 * 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
 */

class Solution {
   public:
    bool isValidBST(TreeNode* root) { return dfs(root, INT_MIN, INT_MAX); }

   private:
    bool dfs(TreeNode* root, long long minV, long long maxV) {
        if (!root) return true;
        if (root->val < minV || root->val > maxV) return false;
        return dfs(root->left, minV, root->val - 1ll) &&
               dfs(root->right, root->val + 1ll, maxV);
    }
};