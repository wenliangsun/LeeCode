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
    /**
     * 枚举每一个顶点
     */
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

    /**
     * 前缀和 + 回溯
     */
    unordered_map<int, int> hash;
    int pathSum(TreeNode* root, int sum) {
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