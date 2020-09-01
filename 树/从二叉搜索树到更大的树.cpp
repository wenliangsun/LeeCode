#include <bits/stdc++.h>

using namespace std;

/**
 * 题目1038：从二叉搜索树到更大和树
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    int pre = 0;
    /**
     * 倒着的中序遍历
     */
    TreeNode* bstToGst(TreeNode* root) {
        if (!root) return root;
        bstToGst(root->right);
        root->val += pre;
        pre = root->val;
        bstToGst(root->left);
        return root;
    }
};