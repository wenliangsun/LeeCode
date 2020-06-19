#include <bits/stdc++.h>

#include "TreeNode.h"

using namespace std;

/**
 * 题目107：二叉树的层次遍历II
 */
class LeeCode107 {
   public:
    /**
     * 不利用栈数据结构，直接将层序遍历的结果翻转
     */
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            vector<int> t;
            int len = 0;
            for (int i = 0; i < len; i++) {
                auto node = q.front();
                q.pop();
                t.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(t);
        }
        reverse(res.begin(), res.end());
        return res;
    }

    /**
     * 思路：利用队列进行层次遍历二叉树，然后利用栈实现翻转
     */
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        stack<vector<int>> stk;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> temp;
            int len = q.size();
            // 遍历一层
            for (int i = 0; i < len; i++) {
                TreeNode* node = q.front();
                temp.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
                q.pop();
            }
            // 入栈
            stk.push(temp);
        }
        // 实现翻转
        while (!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }
};