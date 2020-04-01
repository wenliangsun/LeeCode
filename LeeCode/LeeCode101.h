#include <queue>

#include "TreeNode.h"

using namespace std;

/**
 * 题目101：对称二叉树
 */
class LeeCode101 {
   public:
    /**
     * 思路：递归法
     */
    bool isSymmetric(TreeNode* root) { return isSymmetric(root, root); }

    /**
     * 思路：迭代法
     */
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()) {
            TreeNode* left = q.front();
            q.pop();
            TreeNode* right = q.front();
            q.pop();
            if (left == nullptr && right == nullptr) {
                continue;
            }
            if (left == nullptr || right == nullptr) {
                return false;
            }
            if (left->val != right->val) {
                return false;
            }
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }

   private:
    bool isSymmetric(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        }
        if (root1 == nullptr || root2 == nullptr) {
            return false;
        }
        if (root1->val != root2->val) {
            return false;
        }
        return isSymmetric(root1->left, root2->right) &&
               isSymmetric(root1->right, root2->left);
    }
};