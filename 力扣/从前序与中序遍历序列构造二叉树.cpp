#include <iostream>
#include <unordered_map>
#include <vector>

#include "TreeNode.h"

using namespace std;

/**
 * 题目105：从前序和中序遍历序列构造二叉树
 */
class Solution {
   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; i++) pos[inorder[i]] = i;
        return dfs(preorder, inorder, 0, n - 1, 0, n - 1);
    }

   private:
    unordered_map<int, int> pos;  // 在中序遍历中查找根节点的位置 时间复杂度是O(1)
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int pl, int pr,
                  int il, int ir) {
        if (pl > pr) return nullptr;
        int val = preorder[pl];
        int k = pos[val];
        int len = k - il;
        auto root = new TreeNode(val);
        root->left = dfs(preorder, inorder, pl + 1, pl + len, il, k - 1);
        root->right = dfs(preorder, inorder, pl + len + 1, pr, k + 1, ir);
        return root;
    }
};