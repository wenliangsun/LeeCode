#include <climits>

#include "TreeNode.h"

using namespace std;

class Solution {
   public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }

   private:
    int res = INT_MIN;
    int dfs(TreeNode* root) {
        if (!root) return 0;
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        // 左边最大值+右边最大值
        res = max(res, left + root->val + right);
        // 如果以当前结点为根节点的树的路径和小于0，则不要了
        return max(0, root->val + max(left, right));
    }
};