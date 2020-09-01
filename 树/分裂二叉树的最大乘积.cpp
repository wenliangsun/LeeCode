#include <bits/stdc++.h>

using namespace std;

/**
 * 题目1339：分裂二叉树的最大乘积
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    int sum = 0, best = 0;
    int mod = 1e9 + 7;
    /**
     * 思路1：首先计算所有结点的和sum，然后寻找断开点，以断开点为根节点的子树的和为sum_t，
     * 则我们需要求的是 (sum - sum_t) * sum_t的最大值
     */
    int maxProduct(TreeNode* root) {
        dfs(root);
        dfs2(root);
        return ((long long)best * (sum - best)) % mod;
    }
    //寻找最优的断开点  利用均值不等式的性质
    int dfs2(TreeNode* root) {
        if (!root) return 0;
        int cur = root->val + dfs2(root->left) + dfs2(root->right);
        if (abs(cur * 2 - sum) < abs(best * 2 - sum)) best = cur;
        return cur;
    }
    // 用来计算所有结点的和
    void dfs(TreeNode* root) {
        if (!root) return;
        sum += root->val;
        dfs(root->left);
        dfs(root->right);
    }

    /**
     * 思路2：我们可以用后序遍历记录以每一个结点作为根节点的子树的和，然后再遍历来计算上面的式子求最大值。
     */
    vector<long long> tmp;
    int maxProduct(TreeNode* root) {
        long long res = 0;
        dfs3(root);
        for (int i = 0; i < tmp.size() - 1; i++) {
            res = max(res, tmp[i] * (tmp.back() - tmp[i]));
        }
        return (int)(res % mod);
    }
    // 后序遍历求的每个结点作为根节点的子树和
    int dfs3(TreeNode* root) {
        if (!root) return 0;
        int cur = root->val + dfs3(root->left) + dfs3(root->right);
        tmp.push_back(cur);
        return cur;
    }
};