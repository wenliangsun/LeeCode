#include <bits/stdc++.h>

#include "TreeNode.h"

using namespace std;

/**
 * 题目129：求根到叶子结点数字之和
 */

class Solution {
   public:
    int res = 0;
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return res;
    }

    void dfs(TreeNode* root, int path) {
        if (root == nullptr) return;
        if (root->right == nullptr && root->left == nullptr) {
            res += path * 10 + root->val;
            return;
        }
        path = path * 10 + root->val;
        dfs(root->left, path);
        dfs(root->right, path);
    }
};