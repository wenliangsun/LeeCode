#include <bits/stdc++.h>

#include "TreeNode.h"

using namespace std;

/**
 * 题目199：二叉树的右视图
 */

class Solution {
   public:
    /**
     * 层序遍历
     */
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                auto node = q.front();
                if (i == len - 1) res.push_back(node->val);
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return res;
    }
};
