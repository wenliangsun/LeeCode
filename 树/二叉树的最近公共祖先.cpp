#include "TreeNode.h"

class Solution {
   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 如果以root为根的子树中包含p或q，则返回它们的最近公共祖先
        // 如果只包含p，则返回p
        // 如果只包含q，则返回q
        // 如果都不包含，则返回null
        if (!root || root == p || root == q) return root;
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        // 如果左边不包含
        // 如果右边也不包含，则right为null，最终返回null
        // 如果右边只包含p或q，则right=p或q，最终返回p或q
        // 如果右边同时包含p或q，则right是最近公共祖先，最终返回最近公共祖先。
        if (!left) return right;
        if (!right) return left;
        // 如果左右两边都不为null，说明左右两边各包含一个，此时当前结点是最近公共祖先
        return root;
    }
};