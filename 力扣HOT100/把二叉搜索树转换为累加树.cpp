#include <bits/stdc++.h>

using namespace std;

/**
 * 题目538：把二叉搜索树转换为累加树
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    int pre = 0;  // 记录比当前结点大的值的和
    // 中序遍历倒过来
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return root;
        convertBST(root->right);  // 先去右子树
        root->val += pre;         // 更新当前节点的值
        pre = root->val;          // 更新pre
        convertBST(root->left);   // 去左子树
        return root;
    }
};
