#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    /**
     * 二分的思想
     * 递归，求子树的高度：如果当前根节点为叶子节点，则返回；如果左子树高度>右子树高度，则在左子树继续递归过程；
     * 否则在右子树继续递归。由于是完全二叉树，求高度时只需一直往左遍历即可。每次递归都下降一层，每次都求树的高度，
     * 时间复杂度为O(lgN * lgN)
     */
    TreeNode* getLastNode(TreeNode* root) {
        if (!root || !root->left) return root;
        int lh = 0;
        auto node = root->left;
        while (node) {
            node = node->left;
            lh++;
        }
        int rh = 0;
        node = root->right;
        while (node) {
            node = node->left;
            rh++;
        }
        if (lh > rh)
            return getLastNode(root->left);
        else
            return getLastNode(root->right);
    }
};

/*
 * 迭代
 * O(log N * log N)
 */
class SolutionI {
   public:
    TreeNode* getLastNode(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return root;
        int height = 0;  // 树高度
        TreeNode* node = root;
        while (node) {
            node = node->left;
            ++height;
        }

        TreeNode* last = root;  // 当前比较的左子树和右子树的根节点
        while (last->left != nullptr) {  // 指向叶子节点时退出
            int lh = --height;
            int rh = 0;
            node = last->right;
            while (node) {
                ++rh;
                node = node->left;
            }
            if (lh > rh)
                last = last->left;
            else
                last = last->right;
        }

        return last;
    }
};
