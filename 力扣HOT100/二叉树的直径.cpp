#include <bits/stdc++.h>

using namespace std;

/**
 * 二叉树的直径
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    int res = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        dfs(root);
        return res;
    }

    int dfs(TreeNode* root) {
        if (!root) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        res = max(res, l + r);
        return max(l, r) + 1;
    }
};