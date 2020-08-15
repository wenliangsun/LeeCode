#include <bits/stdc++.h>

using namespace std;

/**
 * 路径总和系列
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
     * 路径总和I
     * 回溯 dfs
     * 时间复杂度：O(n)
     * 空间复杂度：O(h) h为树的高度，递归时候栈空间的开销
     */
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right) return sum - root->val == 0;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }

    /**
     * 路径总和II
     * 回溯 + dfs
     * 时间复杂度：O(n)
     * 空间复杂度：O(h) h为树的高度
     */
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root) return res;
        vector<int> path;
        dfs(root, sum, path);
        return res;
    }

    void dfs(TreeNode* root, int sum, vector<int>& path) {
        if (!root) return;
        path.push_back(root->val);
        if (!root->left && !root->right && sum - root->val == 0) res.push_back(path);
        dfs(root->left, sum - root->val, path);
        dfs(root->right, sum - root->val, path);
        path.pop_back();
    }

    /**
     * 路径总和III
     * 枚举每一个结点作为顶点
     */
    int pathSumIII(TreeNode* root, int sum) {
        if (!root) return 0;
        auto res = dfs(root, sum);
        auto l = pathSumIII(root->left, sum);
        auto r = pathSumIII(root->right, sum);
        return res + l + r;
    }

    int dfs(TreeNode* root, int sum) {
        if (!root) return 0;
        sum -= root->val;
        int res = sum == 0;
        return res + dfs(root->left, sum) + dfs(root->right, sum);
    }

    /**
     * 路径总和III
     * 前缀和 + 回溯
     * 时间复杂度：O(n)
     * 空间复杂度：O(n)
     */
    unordered_map<int, int> hash;
    int pathSumIII(TreeNode* root, int sum) {
        if (!root) return 0;
        hash[0] = 1;
        return dfs(root, sum, 0);
    }

    int dfs(TreeNode* root, int sum, int cur) {
        if (!root) return 0;
        int res = 0;
        cur += root->val;
        if (hash.count(cur - sum)) res += hash[cur - sum];
        hash[cur]++;
        res += dfs(root->left, sum, cur);
        res += dfs(root->right, sum, cur);
        hash[cur]--;
        return res;
    }
};