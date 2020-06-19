#include "TreeNode.h"

class Solution {
   public:
    // 思路枚举所有的最高点
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return res;
    }

   private:
    int res = 0;
    int dfs(TreeNode* root) {
        if (!root) return 0;
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        // 左边最长路径+右边最长路径
        res = max(res, left + right);
        return max(left + 1, right + 1);
    }
};