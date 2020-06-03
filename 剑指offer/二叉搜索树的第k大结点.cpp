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
    int res = 0, cnt = 0;
    int kthLargest(TreeNode* root, int k) {
        dfs(root, k);
        return res;
    }

    void dfs(TreeNode* root, int k) {
        if (!root) return;
        dfs(root->right, k);
        cnt++;
        if (cnt == k) {
            res = root->val;
            return;
        }
        dfs(root->left, k);
    }
};