#include <vector>

#include "TreeNode.h"

using namespace std;

/**
 * 将有序数组转换成二叉搜索树
 */
class LeeCode108 {
   public:
    /**
     * 思路：二叉搜索树的中序遍历获得的结果就是一个递增的序列，而该问题是一个逆问题
     * 又由于题目要求转换的二叉树是平衡二叉树，说明根节点都在数组中的中间！！！
     */
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) {
            return nullptr;
        }
        return helper(nums, 0, nums.size() - 1);
    }

   private:
    TreeNode* helper(vector<int> nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        // 将当前区间的中间值作为根节点
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        // 左区间用于生成左子树
        root->left = helper(nums, left, mid - 1);
        // 右区间用于生成右子树
        root->right = helper(nums, mid + 1, right);
        return root;
    }
};