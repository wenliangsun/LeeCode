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
     * 自底向上
     * 时间复杂度：O(n)
     */
    bool isBalanced(TreeNode* root) {
        return dfs2(root) >= 0;
    }

    int dfs2(TreeNode* root) {
        if (!root) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        if (l == - 1 || r == -1 || abs(l - r) > 1) return -1;
        return max(l, r) + 1;
    }

    /**
     * 自顶向下
     * 时间复杂度：O(n^2)
     */
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int l = dfs(root->left);
        int r = dfs(root->right);
        return abs(l - r) < 2 && isBalanced(root->left) && isBalanced(root->right);
    }

    int dfs(TreeNode* root) {
        if (!root) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        return max(l, r) + 1;
    }
};