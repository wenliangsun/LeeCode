#include <bits/stdc++.h>

#include "TreeNode.h"

using namespace std;

/**
 * 从中序与后序遍历序列构建二叉树
 */

class Solution {
   public:
    unordered_map<int, int> pos;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) pos[inorder[i]] = i;
        return dfs(inorder, postorder, 0, n - 1, 0, n - 1);
    }

    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder, int il, int ir,
                  int pl, int pr) {
        if (il > ir) return nullptr;
        int val = postorder[pr];
        int k = pos[val];
        int len = k - il;
        auto root = new TreeNode(val);
        root->left = dfs(inorder, postorder, il, k - 1, pl, pl + len - 1);
        root->right = dfs(inorder, postorder, k + 1, ir, pl + len, pr - 1);
        return root;
    }
};