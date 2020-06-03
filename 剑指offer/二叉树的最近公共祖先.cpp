#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    /**
     * 根据定义：以root最低公共祖先的情况有三种
     * 1.p和q在root的子树中，并且p和q在root的两侧
     * 2.p=root,且q在root的左或右子树中
     * 3.q=root，且p在root的左或右子树中
     *
     */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;  // 第23种情况
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        if (!left) return right;  // 说明在右子树或都为空
        if (!right) return left;  // 说明在左子树或都为空
        return root;              // 左右都不为null，说明左右各一个
    }
};