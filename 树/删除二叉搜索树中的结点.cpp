#include <bits/stdc++.h>

using namespace std;

/**
 * 题目450：删除二叉搜索树中的结点
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    /**
     * 分情况讨论
     * 1.如果没有找到删除的结点，遍历到空节点直接返回；
     * 2.找到删除的结点：
     *    (1) 如果结点的左右都为null，则直接删除，返回null；
     *    (2) 如果左孩子为null，则删除结点，右孩子补位，返回右孩子；
     *    (3) 如果右孩子为null，则删除结点，左孩子补位，返回左孩子；
     *    (4) 如果左右孩子都不为null，则删除结点，将结点的左孩子放在结点的右孩子的最左面的孩子上，返回结点的右孩子；
     */
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root; // 如果没有找到删除的结点，遍历到空节点直接返回
        if (root->val == key) { // 找到了
            if (!root->left) return root->right; // 如果左孩子为null(或左右都为null)
            else if (!root->right) return root->left; // 如果右孩子为null
            else { // 左右孩子都不为null
                auto cur = root->right; // 寻找右孩子的最左面结点
                while (cur->left) {
                    cur = cur->left;
                }
                cur->left = root->left; // 右孩子的最左面结点的left指针指向删除结点的左孩子
                root = root->right; // 返回删除结点的右孩子
                return root;
            }
        }
        if (root->val > key) root->left = deleteNode(root->left, key);
        if (root->val < key) root->right = deleteNode(root->right, key);
        return root;
    }
};