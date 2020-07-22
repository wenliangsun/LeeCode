#include <bits/stdc++.h>

using namespace std;

/**
 * 二叉树中的最大路径和
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }

    int dfs(TreeNode* root) {
        if (!root) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        res = max(res, l + r + root->val);
        return max(0, max(l, r) + root->val);
    }
};