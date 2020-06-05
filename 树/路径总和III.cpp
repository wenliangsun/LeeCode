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
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        auto res = dfs(root, sum);
        auto l = pathSum(root->left, sum);
        auto r = pathSum(root->right, sum);
        return res + l + r;
    }

    int dfs(TreeNode* root, int sum) {
        if (!root) return 0;
        sum -= root->val;
        auto t = sum == 0 ? 1 : 0;
        return t + dfs(root->left, sum) + dfs(root->right, sum);
    }
};