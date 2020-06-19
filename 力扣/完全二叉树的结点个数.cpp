#include <bits/stdc++.h>

using namespace std;

/**
 * 题目222：完全二叉树的结点个数
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    int countNodes(TreeNode *root) {
        if (!root) return 0;
        int res = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (q.size()) {
            int len = q.size();
            res += len;
            for (int i = 0; i < len; i++) {
                auto node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return res;
    }
};