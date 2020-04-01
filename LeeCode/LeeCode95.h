#include <vector>

#include "TreeNode.h"

using namespace std;

/**
 * 题目95：不同的二叉搜索树II
 */
class LeeCode95 {
   public:
    /**
     * 思路：递归法，利用二叉搜索树的性质即左子树都小于根节点，右子树都大于根节点
     */
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if (n == 0) {
            return res;
        }
        res = helper(1, n);
        return res;
    }

    /**
     * 思路：动态规划
     */
    vector<TreeNode*> generateTrees2(int n) {
        vector<vector<TreeNode*>> dp(n + 1, vector<TreeNode*>());
        if (n == 0) {
            return dp[0];
        }
        dp[0].push_back(nullptr);
        // 区间从1 到 n
        for (int end = 1; end <= n; end++) {
            // 区间中的每一个数作为根节点
            for (int mid = 1; mid <= end; mid++) {
                // 获取左区间的所有左子树
                for (auto leftTree : dp[mid - 1]) {
                    // 获取右区间的所有右子树
                    for (auto rightTree : dp[end - mid]) {
                        TreeNode* root = new TreeNode(mid);
                        root->left = leftTree;
                        // 克隆右子树并加上偏差
                        root->right = clone(rightTree, mid);
                        dp[end].push_back(root);
                    }
                }
            }
        }
        return dp[n];
    }

   private:
    /**
     * 递归法，运用二叉搜索树的性质
     */
    vector<TreeNode*> helper(int begin, int end) {
        vector<TreeNode*> res;
        // 当前区间没有数字，添加null
        if (begin > end) {
            res.push_back(nullptr);
            return res;
        }
        // 当前区间只有一个数字，则将其作为树添加进去
        if (begin == end) {
            TreeNode* tree = new TreeNode(begin);
            res.push_back(tree);
            return res;
        }
        // 尝试每个数字作为根节点
        for (int i = begin; i <= end; i++) {
            // 递归获取所有可能的左子树 ，左区间
            vector<TreeNode*> leftTrees = helper(begin, i - 1);
            // 递归获取所有可能的右子树， 右区间
            vector<TreeNode*> rightTrees = helper(i + 1, end);
            // 以当前结点为根节点，两两组合左右子树
            for (auto leftTree : leftTrees) {
                for (auto rightTree : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftTree;
                    root->right = rightTree;
                    res.push_back(root);
                }
            }
        }
        return res;
    }

    /**
     * 带偏置复制二叉树
     */
    TreeNode* clone(TreeNode* tree, int offset) {
        if (tree == nullptr) {
            return tree;
        }
        TreeNode* root = new TreeNode(tree->val + offset);
        root->left = clone(tree->left, offset);
        root->right = clone(tree->right, offset);
        return root;
    }
};