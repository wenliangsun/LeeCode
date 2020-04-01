#include <stack>
#include <unordered_map>
#include <vector>

#include "TreeNode.h"

using namespace std;

/**
 * 题目145：二叉树的后序遍历
 */
class LeeCode145 {
   public:
    /**
     * 思路：递归法
     */
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return res;
        }
        helper(root);
        return res;
    }

    /**
     * 思路：非递归法 DFS
     */
    vector<int> postorderTraversal2(TreeNode* root) {
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
        helper(root->left);
        helper(root->right);
        res.push_back(root->val);
    }
};