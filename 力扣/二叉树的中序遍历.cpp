#include <stack>
#include <vector>

#include "TreeNode.h"

using namespace std;

/**
 * 题目94：二叉树的中序遍历
 */
class LeeCode94 {
   public:
    /**
     * 思路：递归法
     */
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return res;
        }
        DFS(root);
        return res;
    }

    /**
     * 思路：非递归版本
     * 使用栈数据结构
     */
    vector<int> inorderTraversal2(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res;
        while (root != nullptr || !stk.empty()) {
            // 遍历左子树，左子树依次入栈
            while (root) {
                stk.push(root);
                root = root->left;
            }
            // 遍历当前结点
            root = stk.top();
            stk.pop();
            res.push_back(root->val);
            // 遍历右子树
            root = root->right;
        }
        return res;
    }

    /**
     * 思路：莫里斯法
     */
    vector<int> inorderTraversal3(TreeNode* root) {}

   private:
    vector<int> res;
    /**
     * 二叉树的中序遍历，递归版本
     */
    void DFS(TreeNode* root) {
        if (root != nullptr) {
            res = inorderTraversal(root->left);
            res.push_back(root->val);
            res = inorderTraversal(root->right);
        }
    }
};