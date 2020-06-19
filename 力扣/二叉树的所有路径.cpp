#include <bits/stdc++.h>

using namespace std;

/**
 * 题目257：二叉树的所有路径
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    vector<string> res;
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> path;
        dfs(root, path);
        return res;
    }

    void dfs(TreeNode *root, vector<string> &path) {
        if (!(root->left) && !(root->right)) {
            string t;
            for (auto s : path) t += s + "->";
            t += to_string(root->val);
            res.push_back(t);
            return;
        }
        path.push_back(to_string(root->val));
        dfs(root->left, path);
        dfs(root->right, path);
        path.pop_back();
    }
};