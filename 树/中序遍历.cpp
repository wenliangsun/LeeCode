#include <iostream>
#include <stack>
#include <vector>

#include "TreeNode.h"

using namespace std;

/**
 * 中序遍历
 */
class Solution {
   public:
    /**
     * 递归版本
     */
    vector<int> inorderTraversal1(TreeNode* root) {
        if (root == nullptr) {
            return res;
        }
        DFS(root);
        return res;
    }

    /**
     * 非递归版  使用栈
     */
    vector<int> inorderTraversal2(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res;
        while (root != nullptr || !stk.empty()) {
            while (root) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }

   private:
    vector<int> res;
    void DFS(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        DFS(root->left);
        res.push_back(root->val);
        DFS(root->right);
    }
};

int main() {}