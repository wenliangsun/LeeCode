#include "TreeNode.h"

/**
 * 题目112：路径总和
 */
class LeeCode112 {
   public:
    /**
     * 思路：递归法
     */
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) {
            return false;
        }
        // 如果是叶子结点，判断路径和是不是等于目标值
        if (root->left == nullptr && root->right == nullptr) {
            // 注意这儿的判断
            return sum - root->val == 0;
        }
        return hasPathSum(root->left, sum - root->val) ||
               hasPathSum(root->right, sum - root->val);
    }
};