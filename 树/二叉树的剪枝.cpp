#include <bits/stdc++.h>

using namespace std;

/**
 * 二叉树的剪枝
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    TreeNode* pruneTree(TreeNode* root) {
        return containsOne(root) ? root : nullptr;
    }

    bool containsOne(TreeNode* root) {
        if (!root) return false;
        bool l = containsOne(root->left);
        bool r = containsOne(root->right);
        if (!l) root->left = nullptr;
        if (!r) root->right = nullptr;
        return root->val == 1 || l || r;
    }
};