#include <bits/stdc++.h>

using namespace std;

/**
 * 题目700：二叉树搜索树中的搜索
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root || root->val == val) return root;
        if (root->val < val) return searchBST(root->right, val);
        else return searchBST(root->left, val);
    }

    /**
     * 迭代版本
     * 时间复杂度：O(h)
     * 空间复杂度：O(1)
     */
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root && root->val != val) {
            if (root->val < val) root = root->right;
            else root = root->left;
        }
        return root;
    }
};