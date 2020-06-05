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
     * 注意二叉搜索树的性质，可以优化
     */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;  // 第23种情况
        if (root->val < p->val && root->val < q->val)  // p和q都在右子树
            return lowestCommonAncestor(root->right, p, q);
        if (root->val > p->val && root->val > q->val)  // p和q都在左子树
            return lowestCommonAncestor(root->left, p, q);
        return root;  // p和q在两侧
    }
};