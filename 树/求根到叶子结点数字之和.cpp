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
    int res = 0;
    int sumNumbers(TreeNode* root) {
        int path = 0;
        dfs(root, path);
        return res;
    };

    void dfs(TreeNode* root, int path) {
        if (!root) return;
        if (!root->left && !root->right) {
            res += path * 10 + root->val;
            return;
        }
        path = path * 10 + root->val;
        dfs(root->left, path);
        dfs(root->right, path);
    }
};