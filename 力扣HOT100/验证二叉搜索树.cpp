#include <bits/stdc++.h>

using namespace std;

/**
 * 验证二叉搜索树
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    typedef long long LL;
    // 判断当前结点是否在正确的区间
    bool isValidBST(TreeNode* root) { return dfs(root, INT_MIN, INT_MAX); }

    bool dfs(TreeNode* root, LL minV, LL maxV) {
        if (!root) return true;
        if (root->val < minV || root->val > maxV) return false; // 不在正确的区间，返回false
        // 缩小区间 dfs左右子树
        return dfs(root->left, minV, root->val - 1ll) &&
               dfs(root->right, root->val + 1ll, maxV);
    }
};