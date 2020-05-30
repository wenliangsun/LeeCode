#include <bits/stdc++.h>

using namespace std;

/**
 * 二叉树的镜像
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
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr) return root;
        auto t = root->left;
        root->left = mirrorTree(root->right);
        root->right = mirrorTree(t);
        return root;
    }
};