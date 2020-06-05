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