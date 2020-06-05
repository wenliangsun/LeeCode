#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    /**
     * 递归
     */
    TreeNode *pre = nullptr;  // 记录当前结点右子树展开的链表的头结点
    // 后序遍历反过来了
    void flatten(TreeNode *root) {
        if (!root) return;
        flatten(root->right);
        flatten(root->left);
        root->right = pre;  // 当前结点的右指针设置为右子树展开的链表的头结点
        root->left = nullptr;  // 左子树置空
        pre = root;            // 更新头结点
    }

    /**
     * 非递归版
     */
    void flatten(TreeNode *root) {
        while (root) {
            if (root->left) {
                //寻找当前结点左子树中的最右结点
                auto right = root->left;
                while (right->right) {
                    right = right->right;
                }
                // 最右结点指向当前结点的右子树
                right->right = root->right;
                // 当前结点的右子树设置为当前结点的左子树
                root->right = root->left;
                // 当前结点的左子树置空
                root->left = nullptr;
            }
            root = root->right;
        }
    }
};