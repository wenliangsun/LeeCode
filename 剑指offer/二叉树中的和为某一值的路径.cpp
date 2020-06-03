#include <bits/stdc++.h>

using namespace std;

/**
 * 题目和路径总和II一样
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root) return res;
        vector<int> path;
        dfs(root, sum, path);
        return res;
    }

    /**
     * 回溯法
     */
    void dfs(TreeNode* root, int sum, vector<int>& path) {
        if (!root) return;
        path.push_back(root->val);
        if (!root->left && !root->right && sum - root->val == 0)
            res.push_back(path);
        dfs(root->left, sum - root->val, path);
        dfs(root->right, sum - root->val, path);
        path.pop_back();
    }
};