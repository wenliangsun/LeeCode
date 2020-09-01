#include <bits/stdc++.h>

using namespace std;

/**
 * 不同的二叉搜索树II
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if (!n) return res;
        return dfs(1, n);
    }

    vector<TreeNode*> dfs(int l, int r) {
        vector<TreeNode*> res;
        if (l > r) {
            res.push_back(nullptr);
            return res;
        }
        if (l == r) {
            auto node = new TreeNode(l);
            res.push_back(node);
            return res;
        }
        for (int i = l; i <= r; i++) {// 枚举区间中的所有结点作为根节点
            vector<TreeNode*> leftTrees = dfs(l, i - 1); // 递归左区间
            vector<TreeNode*> rightTrees = dfs(i + 1, r); // 递归有区间没
            // 组合左右区间
            for (auto lt : leftTrees) {
                for (auto rt : rightTrees) {
                    auto root = new TreeNode(i);
                    root->left = lt;
                    root->right = rt;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};