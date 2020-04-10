#include <iostream>
#include <stack>
#include <vector>

#include "TreeNode.h"

using namespace std;

/**
 * 先序遍历
 */
class Solution {
   public:
    /**
     * 递归版本
     */
    vector<int> preorderTraversal1(TreeNode* root) {
        if (root == nullptr) {
            return res;
        }
        DFS(root);
        return res;
    }

    /**
     * 非递归版本 使用栈
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

   private:
    vector<int> res;
    void DFS(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        res.push_back(root->val);
        DFS(root->left);
        DFS(root->right);
    }
};