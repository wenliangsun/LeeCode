#include <bits/stdc++.h>

using namespace std;

/**
 * 打家劫舍III
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    unordered_map<TreeNode*, int> memo;
    int rob(TreeNode* root) {
        if (!root) return 0;
        if (memo.count(root)) return memo[root];
        int do_it = // 如果抢当前结点
            root->val +
            (root->left ? rob(root->left->left) + rob(root->left->right) : 0) +
            (root->right ? rob(root->right->left) + rob(root->right->right): 0);
        int not_do = rob(root->left) + rob(root->right); // 不抢当前结点
        int res = max(do_it, not_do); // 取最大
        memo[root] = res;
        return res;
    }
};