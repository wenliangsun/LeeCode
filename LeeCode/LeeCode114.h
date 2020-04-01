#include <queue>

#include "TreeNode.h"

using namespace std;

/**
 * 题目114：二叉树展开为链表
 */
class LeeCode114 {
   public:
    /**
     * 思路：非递归法
     * 对于根结点，如果没有左子树，则考虑将其右孩子作为根节点
     * 如果有左子树，则寻找左子树中的最右结点，并将根节点的右子树结点该节点上，
     * 并将该节点的左子树放到右子树的位置
     */
    void flatten(TreeNode* root) {
        while (root != nullptr) {
            // 如果有左子树
            if (root->left != nullptr) {
                TreeNode* mostRight = root->left;
                // 寻找左子树的最右结点
                while (mostRight->right != nullptr) {
                    mostRight = mostRight->right;
                }
                // 该节点的右子树接到左子树中最右的结点上
                mostRight->right = root->right;
                // 该结点的左子树放在右子树的位置
                root->right = root->left;
                // 将左子树置为null
                root->left = nullptr;
            }
            // 考察下一个结点
            root = root->right;
        }
    }

    /**
     * 思路：递归版
     * 后序遍历
     */
    void flatten2(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        flatten2(root->right);  // 遍历右子树
        flatten2(root->left);   // 遍历左子树
        root->right = pre;      // 当前结点的右子树连接到前一结点
        root->left = nullptr;   // 当前结点的左子树置为null
        pre = root;             // 更新前一结点
    }

   private:
    TreeNode* pre = nullptr;
};