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
     * 递归即可 注意交换的时候需要借助中间变量
     */
    TreeNode* mirrorTree(TreeNode* root) {
        auto t = root->left;
        root->left = mirrorTree(root->right);
        root->right = mirrorTree(t);
        return root;
    }
};