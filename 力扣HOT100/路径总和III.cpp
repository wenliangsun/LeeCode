#include <bits/stdc++.h>

using namespace std;

/**
 * 路径总和III
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    /**
     * 枚举所有的顶点
     */
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        int res = dfs(root, sum); // 以当前结点为顶点的路径总数
        int l = pathSum(root->left, sum); // 左子树作为顶点
        int r = pathSum(root->right, sum); // 右子树作为顶点
        return res + l + r;
    }

    int dfs(TreeNode* root, int sum) {
        if (!root) return 0;
        sum -= root->val;
        int t = sum == 0;
        return t + dfs(root->left, sum) + dfs(root->right, sum);
    }
};