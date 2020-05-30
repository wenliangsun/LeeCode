#include <bits/stdc++.h>

using namespace std;

/**
 * 题目226：翻转二叉树  同镜像二叉树
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    /**
     * 递归
     */
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;
        auto t = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(t);
        return root;
    }
};