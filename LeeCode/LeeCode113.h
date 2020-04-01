#include <vector>

#include "TreeNode.h"

using namespace std;

/**
 * 题目113：路径总和II
 */
class LeeCode113 {
   public:
    /**
     * 思路：递归法
     */
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == nullptr) {
            return res;
        }
        vector<int> path;
        helper(root, sum, path);
        return res;
    }

   private:
    vector<vector<int>> res;
    /**
     * 实质是二叉树的先序遍历
     */
    void helper(TreeNode* root, int sum, vector<int> path) {
        if (root == nullptr) {
            return;
        }
        // 将当前结点添加进去
        path.push_back(root->val);
        // 是叶子结点而且和为sum则将改路径添加到答案数组
        if (root->left == nullptr && root->right == nullptr &&
            sum - root->val == 0) {
            res.push_back(path);
        }
        helper(root->left, sum - root->val, path);
        helper(root->right, sum - root->val, path);
    }
};