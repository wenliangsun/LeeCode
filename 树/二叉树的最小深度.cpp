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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        // 都为空时，说明当前结点是叶结点，返回1，否则为非空结点+1
        if (!(root->left) || !(root->right)) return l + r + 1;
        return min(l, r) + 1;
    }
};