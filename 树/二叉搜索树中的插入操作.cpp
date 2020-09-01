#include <bits/stdc++.h>

using namespace std;

/**
 * 题目701：二叉搜索树中的插入操作
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
     * 递归版本
     * 时间复杂度：O(h)
     * 空间复杂度：O(h)
     */
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        if (root->val < val)
            root->right = insertIntoBST(root->right, val);
        else
            root->left = insertIntoBST(root->left, val);
        return root;
    }

    /**
     * 迭代版本
     * 时间复杂度：O(h)
     * 空间复杂度：O(1)
     */
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        auto cur = root;
        while (cur) {
            if (val > cur->val) {
                if (cur->right) cur = cur->right;
                else {
                    cur->right = new TreeNode(val);
                    return root;
                }
            } else {
                if (cur->left) cur = cur->left;
                else {
                    cur->left = new TreeNode(val);
                    return root;
                }
            }
        }
        return new TreeNode(val);
    }
};
