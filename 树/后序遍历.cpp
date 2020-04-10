#include <iostream>
#include <stack>
#include <vector>

#include "TreeNode.h"

using namespace std;

/**
 * 后序遍历
 */
class Solution {
   public:
    /**
     * 递归版本
     */
    vector<int> postorderTraversal1(TreeNode* root) {
        if (root == nullptr) {
            return res;
        }
        DFS(root);
        return res;
    }

    /**
     * 非递归版本
     * 可以访问一个结点的条件是：要么该结点的右孩子为空，要么该结点的右孩子已访问过了
     */
    vector<int> postorderTraversal2(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        // 走到最左孩子
        while (cur) {
            stk.push(cur);
            cur = cur->left;
        }
        while (!stk.empty()) {
            cur = stk.top();
            // 当该结点的右孩子为空或者已经被访问的时候，访问该节点
            if (cur->right == nullptr || cur->right == pre) {
                res.push_back(cur->val);
                pre = cur;
                stk.pop();
            } else {
                // 否则去该结点的右子树
                cur = cur->right;
                // 做到最左孩子
                while (cur) {
                    stk.push(cur);
                    cur = cur->left;
                }
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
        DFS(root->left);
        DFS(root->right);
        res.push_back(root->val);
    }
};