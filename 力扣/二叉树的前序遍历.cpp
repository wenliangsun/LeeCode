#include <queue>
#include <stack>
#include <vector>

#include "TreeNode.h"
using namespace std;

/**
 * 题目144：二叉树的前序遍历
 */
class LeeCode144 {
    /**
     * 思路：递归版本
     */
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return res;
        }
        helper(root);
        return res;
    }

    /**
     * 思路：非递归版本 DFS
     */
    vector<int> preorderTraversal2(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();
            res.push_back(node->val);
            if (node->right) {
                stk.push(node->right);
            }
            if (node->left) {
                stk.push(node->left);
            }
        }
        return res;
    }

    /**
     * 思路：莫里斯法(Morris)
     */
    vector<int> preorderTraversal3(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
    }

   private:
    vector<int> res;
    void helper(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        res.push_back(root->val);
        helper(root->left);
        helper(root->right);
    }
};