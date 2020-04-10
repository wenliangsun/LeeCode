#include <iostream>
#include <queue>
#include <vector>

#include "TreeNode.h"

using namespace std;

/**
 * 层序遍历
 */
class Solution {
   public:
    /**
     * 递归版本
     */
    vector<vector<int>> levelOrder1(TreeNode* root) {
        if (root == nullptr) {
            return res;
        }
        DFS(root, 0);
        return res;
    }

    /**
     * 非递归版本
     */
    vector<vector<int>> levelOrder2(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        bool finished = false;
        vector<int> temp;
        while (!q.empty()) {
            if (finished) {
                temp.clear();
            }
            TreeNode* node = q.front();
            if (node != nullptr) {
                temp.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
                q.pop();
                finished = false;
            } else {
                res.push_back(temp);
                q.pop();
                if (!q.empty()) {
                    q.push(nullptr);
                }
                finished = true;
            }
        }
        return res;
    }

   private:
    vector<vector<int>> res;
    void DFS(TreeNode* root, int level) {
        // 此时需要构建下一层
        if (res.size() == level) {
            vector<int> temp;
            res.push_back(temp);
        }
        res[level].push_back(root->val);
        if (root->left) {
            DFS(root->left, level + 1);
        }
        if (root->right) {
            DFS(root->right, level + 1);
        }
    }
};